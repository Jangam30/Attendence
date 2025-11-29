#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Function to create a new node
Node* createNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->prev = nullptr;
    temp->next = nullptr;
    return temp;
}

// Insert node at end
void insertEnd(int value) {
    Node* newNode = createNode(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Display list
void display() {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Bubble sort (swap data method)
void bubbleSort() {
    if (head == nullptr) return;

    bool swapped;
    Node* ptr1;
    Node* last = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != last) {
            if (ptr1->data > ptr1->next->data) {
                // swap values
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        last = ptr1;

    } while (swapped);
}

int main() {
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(val);
    }

    cout << "\nBefore Sorting:\n";
    display();

    bubbleSort();

    cout << "\nAfter Bubble Sort:\n";
    display();

    return 0;
}
