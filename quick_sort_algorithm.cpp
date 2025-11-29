#include <iostream>
using namespace std;

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int passCount = 0;  // global counter for passes

// ----------------- Quick Sort (Lomuto Partition) -----------------
int partitionArray(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // swap arr[i], arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // final swap with pivot
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Print pass
    cout << "Pass " << ++passCount << ": ";
    printArray(arr, n);

    return i + 1;
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int p = partitionArray(arr, low, high, n);

        quickSort(arr, low, p - 1, n);
        quickSort(arr, p + 1, high, n);
    }
}

// ----------------- Divide & Conquer Min-Max -----------------
pair<int,int> findMinMax(int arr[], int low, int high) {
    // If only one element
    if (low == high)
        return {arr[low], arr[low]};

    // If only two elements
    if (high == low + 1) {
        if (arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }

    // Divide
    int mid = (low + high) / 2;

    pair<int,int> left = findMinMax(arr, low, mid);
    pair<int,int> right = findMinMax(arr, mid + 1, high);

    // Combine results
    int minimum = (left.first < right.first) ? left.first : right.first;
    int maximum = (left.second > right.second) ? left.second : right.second;

    return {minimum, maximum};
}

// ----------------- MAIN -----------------
int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int arr[100];

    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal Marks:\n";
    printArray(arr, n);

    // Find min & max before sorting
    pair<int,int> mm = findMinMax(arr, 0, n - 1);

    cout << "\nUsing Divide & Conquer:\n";
    cout << "Minimum Marks = " << mm.first << endl;
    cout << "Maximum Marks = " << mm.second << endl;

    // Quick Sort
    cout << "\nQuick Sort Pass-by-Pass:\n";
    quickSort(arr, 0, n - 1, n);

    // Final sorted output
    cout << "\nFinal Sorted Marks (Ascending Order):\n";
    printArray(arr, n);

    return 0;
}
