#include <iostream>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

class VertexClub {
private:
    Node* head;

public:
    VertexClub() { head = nullptr; }

    // Create new node
    Node* createNode(int prn, string name) {
        Node* temp = new Node;
        temp->prn = prn;
        temp->name = name;
        temp->next = nullptr;
        return temp;
    }

    // Insert President (at beginning)
    void insertPresident(int prn, string name) {
        Node* newNode = createNode(prn, name);
        newNode->next = head;
        head = newNode;
    }

    // Insert Secretary (at end)
    void insertSecretary(int prn, string name) {
        Node* newNode = createNode(prn, name);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert Member (at given position)
    void insertMember(int prn, string name, int pos) {
        if (pos == 1) {
            insertPresident(prn, name);
            return;
        }

        Node* newNode = createNode(prn, name);
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Position out of range!\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete President
    void deletePresident() {
        if (head == nullptr) {
            cout << "List empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete Secretary
    void deleteSecretary() {
        if (head == nullptr) {
            cout << "List empty!\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete by PRN
    void deleteByPRN(int prn) {
        if (head == nullptr) return;

        if (head->prn == prn) {
            deletePresident();
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->prn != prn)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Member not found!\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // Count members
    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display list
    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List empty!\n";
            return;
        }
        cout << "\nPRN\tName\n";
        while (temp != nullptr) {
            cout << temp->prn << "\t" << temp->name << endl;
            temp = temp->next;
        }
    }

    // Search by PRN
    void search(int prn) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->prn == prn) {
                cout << "Member Found: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Member not found!" << endl;
    }

    // Sort list by PRN (Bubble sort)
    void sortByPRN() {
        if (head == nullptr) return;

        bool swapped;
        Node* ptr;
        do {
            swapped = false;
            ptr = head;

            while (ptr->next != nullptr) {
                if (ptr->prn > ptr->next->prn) {
                    swap(ptr->prn, ptr->next->prn);
                    swap(ptr->name, ptr->next->name);
                    swapped = true;
                }
                ptr = ptr->next;
            }
        } while (swapped);
    }

    // Reverse linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;

        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    // Concatenate two club lists
    void concatenate(VertexClub &c2) {
        if (head == nullptr) {
            head = c2.head;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = c2.head;
        c2.head = nullptr;
    }
};

// ---------------------------- MAIN PROGRAM ----------------------------

int main() {
    VertexClub divA, divB;
    int choice, prn, pos;
    string name;

    while (true) {
        cout << "\n===== VERTEX CLUB MENU =====\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Add Member\n";
        cout << "4. Delete President\n";
        cout << "5. Delete Secretary\n";
        cout << "6. Delete by PRN\n";
        cout << "7. Count Members\n";
        cout << "8. Display Members\n";
        cout << "9. Search by PRN\n";
        cout << "10. Sort by PRN\n";
        cout << "11. Reverse List\n";
        cout << "12. Concatenate Division B into A\n";
        cout << "13. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter PRN and Name: ";
            cin >> prn >> name;
            divA.insertPresident(prn, name);
            break;

        case 2:
            cout << "Enter PRN and Name: ";
            cin >> prn >> name;
            divA.insertSecretary(prn, name);
            break;

        case 3:
            cout << "Enter PRN, Name, Position: ";
            cin >> prn >> name >> pos;
            divA.insertMember(prn, name, pos);
            break;

        case 4:
            divA.deletePresident();
            break;

        case 5:
            divA.deleteSecretary();
            break;

        case 6:
            cout << "Enter PRN to delete: ";
            cin >> prn;
            divA.deleteByPRN(prn);
            break;

        case 7:
            cout << "Total Members: " << divA.countMembers() << endl;
            break;

        case 8:
            divA.display();
            break;

        case 9:
            cout << "Enter PRN to search: ";
            cin >> prn;
            divA.search(prn);
            break;

        case 10:
            divA.sortByPRN();
            break;

        case 11:
            divA.reverse();
            break;

        case 12:
            cout << "Enter members for Division B (PRN -1 to stop):\n";
            while (true) {
                cin >> prn;
                if (prn == -1) break;
                cin >> name;
                divB.insertSecretary(prn, name);
            }
            divA.concatenate(divB);
            cout << "Lists concatenated!\n";
            break;

        case 13:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
