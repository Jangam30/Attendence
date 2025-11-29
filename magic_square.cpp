#include <iostream>
#include <vector>
using namespace std;

// Print matrix
void printMatrix(const vector<vector<int>>& m, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
}

// Verify magic square
bool verifyMagicSquare(const vector<vector<int>>& m, int n) {
    int magicSum = 0;

    for(int j = 0; j < n; j++)
        magicSum += m[0][j];

    for(int i = 0; i < n; i++) {
        int rowSum = 0;
        for(int j = 0; j < n; j++) rowSum += m[i][j];
        if(rowSum != magicSum) return false;
    }

    for(int j = 0; j < n; j++) {
        int colSum = 0;
        for(int i = 0; i < n; i++) colSum += m[i][j];
        if(colSum != magicSum) return false;
    }

    int diag1 = 0, diag2 = 0;
    for(int i = 0; i < n; i++) diag1 += m[i][i];
    for(int i = 0; i < n; i++) diag2 += m[i][n-i-1];

    if(diag1 != magicSum || diag2 != magicSum)
        return false;

    return true;
}

// Odd order magic square (Siamese)
vector<vector<int>> oddMagic(int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));

    int num = 1;
    int i = 0, j = n/2;

    while(num <= n*n) {
        m[i][j] = num++;

        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if(m[newi][newj] != 0)
            i = (i + 1) % n;
        else {
            i = newi;
            j = newj;
        }
    }
    return m;
}

// Doubly even magic square (n % 4 == 0)
vector<vector<int>> doublyEvenMagic(int n) {
    vector<vector<int>> m(n, vector<int>(n));
    int num = 1, rev = n*n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i % 4 == j % 4) || ((i + j) % 4 == 3))
                m[i][j] = rev--;
            else
                m[i][j] = num++;
        }
    }
    return m;
}

// Singly even magic square (n % 4 == 2)
vector<vector<int>> singlyEvenMagic(int n) {
    int half = n / 2;
    int subSize = half * half;

    vector<vector<int>> M = oddMagic(half);
    vector<vector<int>> magic(n, vector<int>(n));

    for(int i = 0; i < half; i++) {
        for(int j = 0; j < half; j++) {

            magic[i][j]             = M[i][j];
            magic[i][j + half]      = M[i][j] + 2 * subSize;
            magic[i + half][j]      = M[i][j] + 3 * subSize;
            magic[i + half][j + half] = M[i][j] + subSize;
        }
    }

    int k = (n - 2) / 4;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            if(i < half)
                swap(magic[i][j], magic[i + half][j]);
        }

        for(int j = n - k + 1; j < n; j++) {
            if(i < half)
                swap(magic[i][j], magic[i + half][j]);
        }
    }

    return magic;
}

// MAIN
int main() {
    int n;
    cout << "Enter order of Magic Square (n >= 3): ";
    cin >> n;

    if(n < 3) {
        cout << "Magic Square not possible for n < 3\n";
        return 0;
    }

    vector<vector<int>> magic;

    if(n % 2 == 1) {
        cout << "\nConstructing Odd Order Magic Square...\n";
        magic = oddMagic(n);
    }
    else if(n % 4 == 0) {
        cout << "\nConstructing Doubly Even Magic Square...\n";
        magic = doublyEvenMagic(n);
    }
    else {
        cout << "\nConstructing Singly Even Magic Square...\n";
        magic = singlyEvenMagic(n);
    }

    cout << "\nMagic Square of order " << n << ":\n";
    printMatrix(magic, n);

    if(verifyMagicSquare(magic, n))
        cout << "\nMagic Square Verified Successfully!\n";
    else
        cout << "\nVerification Failed!\n";

    return 0;
}
