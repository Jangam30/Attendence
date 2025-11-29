#include <iostream>
#include <string>
using namespace std;

// Node for patient
struct Node {
    string name;
    Node* next;
};

// Queue class for FCFS
class PatientQueue {
private:
    Node* front;
    Node* rear;

public:
    PatientQueue() {
        front = rear = nullptr;
    }

    // Add a new patient (enqueue)
    void checkIn(string patientName) {
        Node* newNode = new Node{patientName, nullptr};

        // If queue empty
        if (rear == nullptr) {
            front = rear = newNode;
        } 
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Patient '" << patientName << "' checked in.\n";
    }

    // Assign doctor to next patient (dequeue)
    void assignDoctor() {
        if (isEmpty()) {
            cout << "No patients waiting!\n";
            return;
        }

        Node* temp = front;
        cout << "Doctor is now seeing: " << front->name << endl;

        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // View next patient
    void nextPatient() {
        if (isEmpty()) {
            cout << "No patients in queue.\n";
        } else {
            cout << "Next patient: " << front->name << endl;
        }
    }

    // Check if queue empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display all waiting patients
    void display() {
        if (isEmpty()) {
            cout << "No patients in waiting list.\n";
            return;
        }

        Node* temp = front;
        cout << "Waiting patients: ";

        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


// ---------------- MAIN PROGRAM ----------------

int main() {
    PatientQueue clinic;
    int choice;
    string name;

    while (true) {
        cout << "\n--- MEDICAL CLINIC PATIENT MANAGEMENT ---\n";
        cout << "1. Check-in new patient\n";
        cout << "2. Assign doctor to next patient\n";
        cout << "3. View next patient\n";
        cout << "4. Display waiting list\n";
        cout << "5. Check if queue is empty\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patient name: ";
            cin >> name;
            clinic.checkIn(name);
            break;

        case 2:
            clinic.assignDoctor();
            break;

        case 3:
            clinic.nextPatient();
            break;

        case 4:
            clinic.display();
            break;

        case 5:
            cout << (clinic.isEmpty() ? "No patients waiting.\n" : "Patients are waiting.\n");
            break;

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
