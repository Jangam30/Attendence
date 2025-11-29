#include <iostream>
using namespace std;

// Function to calculate length of a char array
int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to copy string
void stringCopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Function to reverse string
void stringReverse(char str[]) {
    int len = stringLength(str);
    int start = 0, end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to concatenate two strings
void stringConcat(char str1[], char str2[]) {
    int i = stringLength(str1);
    int j = 0;

    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main() {
    char str1[100], str2[100], copyStr[100];

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    // Length
    cout << "\nLength of first string: " << stringLength(str1);
    cout << "\nLength of second string: " << stringLength(str2);

    // Copy
    stringCopy(copyStr, str1);
    cout << "\n\nCopy of first string: " << copyStr;

    // Reverse
    stringReverse(str1);
    cout << "\nReversed first string: " << str1;

    // Concatenate
    stringConcat(copyStr, str2);
    cout << "\nConcatenation of copied string with second string: " << copyStr;

    return 0;
}
