#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert node into BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Find minimum value node in BST
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "BST is empty!\n";
        return -1;
    }
    Node* temp = root;
    while (temp->left != nullptr)
        temp = temp->left;
    return temp->data;
}

// Find maximum value node in BST
int findMax(Node* root) {
    if (root == nullptr) {
        cout << "BST is empty!\n";
        return -1;
    }
    Node* temp = root;
    while (temp->right != nullptr)
        temp = temp->right;
    return temp->data;
}

// Level-wise display of BST
void levelOrderDisplay(Node* root) {
    if (!root) {
        cout << "BST is empty.\n";
        return;
    }
    queue<Node*> q;
    q.push(root);

    cout << "Level-wise BST: ";
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << "\n";
}

// ---------------- MAIN PROGRAM -----------------

int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- BINARY SEARCH TREE MENU ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Display BST Level-wise\n";
        cout << "3. Find Minimum\n";
        cout << "4. Find Maximum\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            levelOrderDisplay(root);
            break;

        case 3:
            cout << "Minimum value in BST: " << findMin(root) << "\n";
            break;

        case 4:
            cout << "Maximum value in BST: " << findMax(root) << "\n";
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
