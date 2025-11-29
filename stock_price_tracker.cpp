#include <iostream>
using namespace std;

// Node of linked list (stack)
struct Node {
    int price;
    Node* next;
};

// Stack class
class StockStack {
private:
    Node* top;

public:
    StockStack() { top = nullptr; }

    // a) Add new stock price
    void record(int price) {
        Node* newNode = new Node;
        newNode->price = price;
        newNode->next = top;
        top = newNode;
        cout << "Recorded price: " << price << endl;
    }

    // b) Remove and return most recent price
    int remove() {
        if (isEmpty()) {
            cout << "No prices to remove.\n";
            return -1;
        }
        Node* temp = top;
        int removedPrice = temp->price;
        top = top->next;
        delete temp;
        return removedPrice;
    }

    // c) View latest price
    int latest() {
        if (isEmpty()) {
            cout << "No prices recorded.\n";
            return -1;
        }
        return top->price;
    }

    // d) Check if empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display all prices
    void display() {
        if (isEmpty()) {
            cout << "No prices in history.\n";
            return;
        }
        Node* temp = top;
        cout << "Price History (latest to oldest): ";
        while (temp != nullptr) {
            cout << temp->price << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ---------------- MAIN PROGRAM -----------------

int main() {
    StockStack tracker;
    int choice, price;

    while (true) {
        cout << "\n--- STOCK PRICE TRACKER MENU ---\n";
        cout << "1. Record a new price\n";
        cout << "2. Remove latest price\n";
        cout << "3. View latest price\n";
        cout << "4. Check if empty\n";
        cout << "5. Display all prices\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter price: ";
            cin >> price;
            tracker.record(price);
            break;

        case 2:
            price = tracker.remove();
            if (price != -1)
                cout << "Removed price: " << price << endl;
            break;

        case 3:
            price = tracker.latest();
            if (price != -1)
                cout << "Latest price: " << price << endl;
            break;

        case 4:
            cout << (tracker.isEmpty() ? "No prices recorded." : "Prices available.") << endl;
            break;

        case 5:
            tracker.display();
            break;

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
