#include <iostream>
using namespace std;

// Function to convert normal matrix to sparse matrix (triplet form)
int convertToSparse(int rows, int cols, int matrix[10][10], int sparse[100][3]) {
    int k = 1; // index for sparse matrix (1 because row 0 stores metadata)

    // Traverse the matrix and store non-zero values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;       // row index
                sparse[k][1] = j;       // column index
                sparse[k][2] = matrix[i][j]; // value
                k++;
            }
        }
    }

    // Store metadata in sparse[0]
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1; // number of non-zero elements

    return k; // total sparse rows
}

// Function to display sparse matrix
void displaySparse(int sparse[100][3], int total) {
    cout << "\nRow\tCol\tVal\n";
    for (int i = 0; i < total; i++) {
        cout << sparse[i][0] << "\t"
             << sparse[i][1] << "\t"
             << sparse[i][2] << "\n";
    }
}

// Function for simple transpose of sparse matrix
void simpleTranspose(int sparse[100][3], int tSparse[100][3]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int nonZero = sparse[0][2];

    // Switch rows and columns in header too
    tSparse[0][0] = cols;
    tSparse[0][1] = rows;
    tSparse[0][2] = nonZero;

    int k = 1;

    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= nonZero; i++) {
            if (sparse[i][1] == col) { // match column
                tSparse[k][0] = sparse[i][1]; // new row = old column
                tSparse[k][1] = sparse[i][0]; // new col = old row
                tSparse[k][2] = sparse[i][2];
                k++;
            }
        }
    }
}

int main() {
    int rows, cols;
    int matrix[10][10];
    int sparse[100][3], tSparse[100][3];

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Convert to sparse
    int total = convertToSparse(rows, cols, matrix, sparse);

    cout << "\n--- Sparse Matrix (Compact Representation) ---\n";
    displaySparse(sparse, total);

    // Transpose sparse matrix
    simpleTranspose(sparse, tSparse);

    cout << "\n--- Transposed Sparse Matrix ---\n";
    displaySparse(tSparse, total);

    return 0;
}
