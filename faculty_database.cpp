#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure for Faculty Record
struct Faculty {
    int id;         // Faculty ID (key)
    string name;
    string dept;
    bool isEmpty;

    Faculty() : id(-1), name(""), dept(""), isEmpty(true) {}
};

// Hash Table Class
class FacultyHashTable {
private:
    vector<Faculty> table;
    int capacity;

    // MOD hash function
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    FacultyHashTable(int cap = 10) {
        capacity = cap;
        table.resize(capacity);
    }

    // Insert with linear probing with replacement
    void insert(Faculty f) {
        int idx = hashFunction(f.id);

        // If slot is empty, insert directly
        if (table[idx].isEmpty) {
            table[idx] = f;
            table[idx].isEmpty = false;
            cout << "Faculty inserted at index " << idx << "\n";
            return;
        }

        // Check if existing record is misplaced
        int existingHash = hashFunction(table[idx].id);
        if (existingHash != idx) {
            // Replace the existing misplaced record
            Faculty temp = table[idx];
            table[idx] = f;
            cout << "Faculty replaced at index " << idx << "\n";

            // Reinsert the displaced record
            insert(temp);
            return;
        }

        // Linear probing to find next empty slot
        int i = (idx + 1) % capacity;
        while (i != idx) {
            if (table[i].isEmpty) {
                table[i] = f;
                table[i].isEmpty = false;
                cout << "Faculty inserted at index " << i << "\n";
                return;
            }
            i = (i + 1) % capacity;
        }

        cout << "Hash table full! Cannot insert.\n";
    }

    // Search faculty by ID
    void search(int id) {
        int idx = hashFunction(id);
        int start = idx;

        while (!table[idx].isEmpty) {
            if (table[idx].id == id) {
                cout << "Faculty Found:\n";
                cout << "ID: " << table[idx].id << ", Name: " << table[idx].name
                     << ", Department: " << table[idx].dept << "\n";
                return;
            }
            idx = (idx + 1) % capacity;
            if (idx == start) break; // back to start
        }
        cout << "Faculty with ID " << id << " not found.\n";
    }

    // Display hash table
    void display() {
        cout << "\n--- Faculty Hash Table ---\n";
        for (int i = 0; i < capacity; i++) {
            if (!table[i].isEmpty)
                cout << "Index " << i << ": ID=" << table[i].id
                     << ", Name=" << table[i].name
                     << ", Dept=" << table[i].dept << "\n";
            else
                cout << "Index " << i << ": Empty\n";
        }
    }
};

// ------------------ MAIN PROGRAM ------------------

int main() {
    FacultyHashTable fTable(10); // Hash table of size 10
    int choice;

    while (true) {
        cout << "\n--- Faculty Database Menu ---\n";
        cout << "1. Insert Faculty\n";
        cout << "2. Search Faculty\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Faculty f;
            cout << "Enter Faculty ID: "; cin >> f.id;
            cin.ignore();
            cout << "Enter Name: "; getline(cin, f.name);
            cout << "Enter Department: "; getline(cin, f.dept);
            fTable.insert(f);
        } else if (choice == 2) {
            int id;
            cout << "Enter Faculty ID to search: "; cin >> id;
            fTable.search(id);
        } else if (choice == 3) {
            fTable.display();
        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
