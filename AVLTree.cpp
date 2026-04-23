#include <iostream>
using namespace std;

// Node structure for AVL tree
struct Node {
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

// Function to get the height of a node
int height(Node* node) {
    return node ? node->height : 0;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Function to perform a right rotation
void rotateRight(Node*& y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    y = x;
}

// Function to perform a left rotation
void rotateLeft(Node*& x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    x = y;
}

// Function to insert a value into the AVL tree
void insert(Node*& node, int value) {
    if (!node) {
        node = new Node(value);
        return;
    }

    if (value < node->value) {
        insert(node->left, value);
    }
    else if (value > node->value) {
        insert(node->right, value);
    }
    else {
        return; // Duplicate values are not allowed
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->value) {
        rotateRight(node);
    }

    // Right Right Case
    if (balance < -1 && value > node->right->value) {
        rotateLeft(node);
    }

    // Left Right Case
    if (balance > 1 && value > node->left->value) {
        rotateLeft(node->left);
        rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value) {
        rotateRight(node->right);
        rotateLeft(node);
    }
}

// In-order traversal
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

// Pre-order traversal
void preOrder(Node* root) {
    if (root) {
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal
void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << " ";
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\nAVL Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Pre-order Traversal\n";
        cout << "4. Post-order Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(root, value);
            break;
        case 2:
            cout << "In-order Traversal: ";
            inOrder(root);
            cout << endl;
            break;
        case 3:
            cout << "Pre-order Traversal: ";
            preOrder(root);
            cout << endl;
            break;
        case 4:
            cout << "Post-order Traversal: ";
            postOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
/

