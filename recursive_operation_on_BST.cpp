#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Count leaf nodes recursively
int countLeaves(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// Create mirror image of binary tree recursively
void mirror(Node* root) {
    if (root == nullptr) return;

    // Swap left and right
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

// ---------------- MAIN PROGRAM ----------------

int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- BINARY TREE MENU ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Count Leaf Nodes\n";
        cout << "5. Mirror Image\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter node value: ";
            cin >> value;
            // Simple insert for demonstration: insert in BST fashion
            if (root == nullptr)
                root = createNode(value);
            else {
                Node* temp = root;
                while (true) {
                    if (value < temp->data) {
                        if (temp->left == nullptr) { temp->left = createNode(value); break; }
                        temp = temp->left;
                    } else {
                        if (temp->right == nullptr) { temp->right = createNode(value); break; }
                        temp = temp->right;
                    }
                }
            }
            break;

        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << "\n";
            break;

        case 3:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << "\n";
            break;

        case 4:
            cout << "Number of Leaf Nodes: " << countLeaves(root) << "\n";
            break;

        case 5:
            mirror(root);
            cout << "Binary Tree mirrored!\n";
            break;

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
