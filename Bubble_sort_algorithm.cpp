#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[100];

    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    // Bubble Sort (sorting marks in descending order)
    for (int pass = 0; pass < n - 1; pass++) {

        cout << "\nPass " << pass + 1 << ": ";

        for (int i = 0; i < n - pass - 1; i++) {
            if (marks[i] < marks[i + 1]) {
                // Swap for descending order
                int temp = marks[i];
                marks[i] = marks[i + 1];
                marks[i + 1] = temp;
            }
        }

        // Display array after each pass
        for (int k = 0; k < n; k++) {
            cout << marks[k] << " ";
        }
    }

    // After sorting: Assign roll numbers (1 = Topper)
    cout << "\n\nFinal Sorted Marks (Roll Numbers Assigned):\n";
    cout << "Roll No.\tMarks\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << marks[i] << endl;
    }

    return 0;
}
