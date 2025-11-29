#include <iostream>
#include <string>
using namespace std;

// Node representing each customer call
struct Node {
    string customerName;
    Node* next;
};

// Queue class
class CallQueue {
private:
    Node* front;
    Node* rear;

public:
    CallQueue() {
        front = rear = nullptr;
    }

    // Enqueue a new call
    void receiveCall(string name) {
        Node* newNode = new Node{name, nullptr};

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Call received from: " << name << endl;
    }

    // Dequeue a call when agent assists
    void assistCall() {
        if (isEmpty()) {
            cout << "No calls waiting! System is idle.\n";
            return;
        }

        Node* temp = front;
        cout << "Assisting customer: " << front->customerName << endl;

        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display waiting calls
    void display() {
        if (isEmpty()) {
            cout << "No calls in the waiting queue.\n";
            return;
        }

        cout << "Current Call Queue: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->customerName << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ------------------ MAIN PROGRAM ------------------

int main() {
    CallQueue callCenter;
    int choice;
    string name;

    while (true) {
        cout << "\n--- CALL CENTER QUEUE SYSTEM ---\n";
        cout << "1. Receive new customer call\n";
        cout << "2. Assist next customer\n";
        cout << "3. Display waiting calls\n";
        cout << "4. Check if queue is empty\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                callCenter.receiveCall(name);
                break;

            case 2:
                callCenter.assistCall();
                break;

            case 3:
                callCenter.display();
                break;

            case 4:
                cout << (callCenter.isEmpty() 
                        ? "No calls waiting. System idle.\n"
                        : "Calls are in the queue.\n");
                break;

            case 5:
                cout << "Exiting system...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
