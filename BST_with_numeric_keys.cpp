#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert key into BST
Node* insert(Node* root, int key) {
    if (root == nullptr) return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Find minimum node (used in delete)
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete a node
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

// Find a key
bool findKey(Node* root, int key) {
    if (!root) return false;
    if (key == root->key) return true;
    if (key < root->key) return findKey(root->left, key);
    return findKey(root->right, key);
}

// Show BST level-wise (BFS)
void showBST(Node* root) {
    if (!root) {
        cout << "BST is empty.\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    cout << "BST Level-wise: ";
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << curr->key << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << "\n";
}

// ---------------- MAIN PROGRAM ----------------

int main() {
    Node* root = nullptr;
    int choice, key;

    while (true) {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find\n";
        cout << "4. Show\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            root = insert(root, key);
            break;

        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            root = deleteNode(root, key);
            break;

        case 3:
            cout << "Enter key to find: ";
            cin >> key;
            if (findKey(root, key))
                cout << "Key " << key << " found in BST.\n";
            else
                cout << "Key " << key << " not found.\n";
            break;

        case 4:
            showBST(root);
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
