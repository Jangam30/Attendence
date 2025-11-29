#include <iostream>
using namespace std;

// Node for polynomial term
struct Node {
    int coeff;     // Coefficient
    int pow;       // Power of x
    Node* next;    // Pointer to next term
};

// Function to create a new node
Node* createNode(int c, int p) {
    Node* temp = new Node;
    temp->coeff = c;
    temp->pow = p;
    temp->next = nullptr;
    return temp;
}

// Insert term at end
void insert(Node*& head, int c, int p) {
    Node* newNode = createNode(c, p);
    if(head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Display polynomial
void display(Node* head) {
    while(head != nullptr) {
        cout << head->coeff << "x^" << head->pow;
        if(head->next != nullptr)
            cout << " + ";
        head = head->next;
    }
    cout << endl;
}

// Add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    while(poly1 != nullptr && poly2 != nullptr) {

        if(poly1->pow > poly2->pow) {
            insert(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if(poly1->pow < poly2->pow) {
            insert(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if(sumCoeff != 0)
                insert(result, sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while(poly1 != nullptr) {
        insert(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while(poly2 != nullptr) {
        insert(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Main function
int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    int n, c, p;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n;
    cout << "Enter terms in descending powers (coeff power):\n";
    for(int i = 0; i < n; i++) {
        cin >> c >> p;
        insert(poly1, c, p);
    }

    cout << "\nEnter number of terms in second polynomial: ";
    cin >> n;
    cout << "Enter terms in descending powers (coeff power):\n";
    for(int i = 0; i < n; i++) {
        cin >> c >> p;
        insert(poly2, c, p);
    }

    cout << "\nPolynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node* sum = addPolynomials(poly1, poly2);

    cout << "\nResultant Polynomial (Sum): ";
    display(sum);

    return 0;
}
