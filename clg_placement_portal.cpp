#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

// Structure for student placement record
struct Student {
    int prn;
    string name;
    string department;
    string company;
};

// Hash Table with Separate Chaining
class PlacementPortal {
private:
    vector<list<Student>> table;
    int capacity;
    int size;

    // Hash function (using modulo)
    int hashFunction(int prn) {
        return prn % capacity;
    }

    // Resize hash table when load factor > 0.7
    void rehash() {
        int oldCapacity = capacity;
        capacity *= 2;
        vector<list<Student>> newTable(capacity);

        for (int i = 0; i < oldCapacity; i++) {
            for (auto &student : table[i]) {
                int idx = student.prn % capacity;
                newTable[idx].push_back(student);
            }
        }
        table = move(newTable);
        cout << "Hash table resized. New capacity: " << capacity << "\n";
    }

public:
    PlacementPortal(int cap = 10) : capacity(cap), size(0) {
        table.resize(capacity);
    }

    // Insert a new student
    void insertStudent(const Student &s) {
        if ((size + 1) / (double)capacity > 0.7) rehash();

        int idx = hashFunction(s.prn);
        // Check if PRN already exists
        for (auto &student : table[idx]) {
            if (student.prn == s.prn) {
                cout << "PRN already exists. Cannot insert.\n";
                return;
            }
        }

        table[idx].push_back(s);
        size++;
        cout << "Student inserted successfully.\n";
    }

    // Delete a student by PRN
    void deleteStudent(int prn) {
        int idx = hashFunction(prn);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (it->prn == prn) {
                table[idx].erase(it);
                size--;
                cout << "Student with PRN " << prn << " deleted.\n";
                return;
            }
        }
        cout << "Student with PRN " << prn << " not found.\n";
    }

    // Search a student by PRN
    void searchStudent(int prn) {
        int idx = hashFunction(prn);
        for (auto &student : table[idx]) {
            if (student.prn == prn) {
                cout << "PRN: " << student.prn
                     << ", Name: " << student.name
                     << ", Dept: " << student.department
                     << ", Company: " << student.company << "\n";
                return;
            }
        }
        cout << "Student with PRN " << prn << " not found.\n";
    }

    // Display all students
    void displayAll() {
        cout << "\n--- Placement Records ---\n";
        for (int i = 0; i < capacity; i++) {
            if (!table[i].empty()) {
                cout << "Bucket " << i << ":\n";
                for (auto &student : table[i]) {
                    cout << "  PRN: " << student.prn
                         << ", Name: " << student.name
                         << ", Dept: " << student.department
                         << ", Company: " << student.company << "\n";
                }
            }
        }
    }
};

// ------------------- MAIN PROGRAM -------------------

int main() {
    PlacementPortal portal;
    int choice;

    while (true) {
        cout << "\n--- College Placement Portal ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "Enter PRN: "; cin >> s.prn;
            cin.ignore();
            cout << "Enter Name: "; getline(cin, s.name);
            cout << "Enter Department: "; getline(cin, s.department);
            cout << "Enter Company Placed: "; getline(cin, s.company);
            portal.insertStudent(s);
        } else if (choice == 2) {
            int prn;
            cout << "Enter PRN to delete: "; cin >> prn;
            portal.deleteStudent(prn);
        } else if (choice == 3) {
            int prn;
            cout << "Enter PRN to search: "; cin >> prn;
            portal.searchStudent(prn);
        } else if (choice == 4) {
            portal.displayAll();
        } else if (choice == 5) {
            cout << "Exiting Portal.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
