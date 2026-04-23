/*#include <iostream>
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
}*/

//Apna College AVL Tree

/*#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

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
}

bool isBalanced(Node* root,int* height)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = 0, rh = 0;

    if (isBalanced(root->left, &lh) == false)
    {
        return false;
    }

    if (isBalanced(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;
    
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void main()
{
    Node* root=NULL;
    insert(root,5);
    insert(root, 7);
    insert(root, 4);
    insert(root, 3);
    insert(root, 2);
    int height = 0;
    if (isBalanced(root, &height) == true)
    {
        cout << "Tree is Balanced." << endl;
    }
    else
    {
        cout << "Tree is UnBalanced." << endl;
    }

}*/

//Code with Harry AVL Tree

/*#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    int value;
    node* right;
    node* left;
    int height;
};

int getHeight(node* n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}*/

/*#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree {
public:
    struct Node {
        int value;
        Node* left;
        Node* right;
        int height;

        Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    // Constructor
    AVLTree() : root(nullptr) {}

    // Destructor
    ~AVLTree() {
        deleteTree(root);
    }

    // Get height of a node
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Get balance factor of a node
    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Perform right rotation
    void rotateRight(Node*& y) {
        Node* x = y->left;
        Node* T = x->right;

        x->right = y;
        y->left = T;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        y = x;
    }

    // Perform left rotation
    void rotateLeft(Node*& x) {
        Node* y = x->right;
        Node* T = y->left;

        y->left = x;
        x->right = T;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        x = y;
    }

    // Insert a value into the AVL tree (recursive)
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

    // Wrapper function for insertion
    void insert(int value) {
        insert(root, value);
    }

    // In-order traversal
    void inOrder(Node* node) const {
        if (node) {
            inOrder(node->left);
            cout << node->value << " ";
            inOrder(node->right);
        }
    }

    // Pre-order traversal
    void preOrder(Node* node) const {
        if (node) {
            cout << node->value << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // Post-order traversal
    void postOrder(Node* node) const {
        if (node) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->value << " ";
        }
    }

    // Delete the entire tree
    void deleteTree(Node* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    // Wrapper functions for traversals
    void inOrderTraversal() const {
        cout << "In-order traversal: ";
        inOrder(root);
        cout << endl;
    }

    void preOrderTraversal() const {
        cout << "Pre-order traversal: ";
        preOrder(root);
        cout << endl;
    }

    void postOrderTraversal() const {
        cout << "Post-order traversal: ";
        postOrder(root);
        cout << endl;
    }

    // Check if tree is empty
    bool isEmpty() const {
        return root == nullptr;
    }

    // Get the minimum value node in the tree
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    // Search for a value
    bool search(Node* node, int value) const {
        if (!node) {
            return false;
        }

        if (value == node->value) {
            return true;
        }

        if (value < node->value) {
            return search(node->left, value);
        }

        return search(node->right, value);
    }

    // Wrapper function for search
    bool search(int value) const {
        return search(root, value);
    }
};

int main() {
    AVLTree avl;
    int choice, value;

    do {
        cout << "\n=== AVL Tree Operations ===" << endl;
        cout << "1. Insert Value" << endl;
        cout << "2. Search Value" << endl;
        cout << "3. Display In-order" << endl;
        cout << "4. Display Pre-order" << endl;
        cout << "5. Display Post-order" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            avl.insert(value);
            cout << "Value inserted successfully!" << endl;
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (avl.search(value)) {
                cout << "Value found in the tree!" << endl;
            }
            else {
                cout << "Value not found in the tree!" << endl;
            }
            break;

        case 3:
            if (avl.isEmpty()) {
                cout << "Tree is empty!" << endl;
            }
            else {
                avl.inOrderTraversal();
            }
            break;

        case 4:
            if (avl.isEmpty()) {
                cout << "Tree is empty!" << endl;
            }
            else {
                avl.preOrderTraversal();
            }
            break;

        case 5:
            if (avl.isEmpty()) {
                cout << "Tree is empty!" << endl;
            }
            else {
                avl.postOrderTraversal();
            }
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}*/

/*#include<iostream>
#include<algorithm>
using namespace std;

class AVLtree
{
public:
    struct Node
    {
        int val;
        Node* left;
        Node* right;
        int height;

        Node(int v)
        {
            val = v;
            left = NULL;
            right = NULL;
            height = 1;
        }
    };

    Node* root;

    int height(Node* n)
    {
        if (n != NULL)
        {
            return n->height;
        }
        else
        {
            return 0;
        }
    }

    int balancefactor(Node* n)
    {
        if (n != NULL)
        {
            return height(n->left) - height(n->right);
        }
        else
        {
            return 0;
        }
    }

    AVLtree()
    {
        root = NULL;
    }

    void rotateright(Node*& y)
    {
        Node* x = y->left;
        Node* T = x->right;

        x->right = y;
        y->left = T;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        y = x;
    }

    void rotateleft(Node*& x)
    {
        Node* y = x->right;
        Node* T = y->left;

        y->left = x;
        x->right = T;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        x = y;
    }

    void insert(Node*& node, int val)
    {
        if (node == NULL)
        {
            node = new Node(val);
            return;
        }

        if (val > node->val)
        {
            insert(node->right, val);
        }
        else if(val < node->val)
        {
            insert(node->left, val);
        }
        else
        {
            return;
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balancefactor(node);
        //left left case
        if (balance > 1 && val < node->left->val)
        {
            rotateright(node);
        }
        
        //right right case
        if (balance < -1 && val > node->right->val)
        {
            rotateleft(node);
        }

        //left right case
        if (balance > 1 && val > node->left->val)
        {
            rotateleft(node);
            rotateright(node);
        }
        //right left case
        if (balance < -1 && val < node->right->val)
        {
            rotateright(node);
            rotateleft(node);
        }
    }

    void insert(int val)
    {
        insert(root, val);
    }

    void preOrder(Node* root)
    {
        if (root != NULL)
        {
            cout << root->val << " ";
            if (root->left != NULL) preOrder(root->left);
            if (root->right != NULL) preOrder(root->right);
        }
    }

    void InOrder(Node* r)
    {
        cout << "Data : ";
        if (r != NULL)
        {
            if (r->left != NULL) InOrder(r->left);
            cout << r->val << " ";
            if (r->right != NULL) InOrder(r->right);
        }
    }

    void postOrder(Node* root)
    {
        cout << "Data : ";
        if (root != NULL)
        {
            if (root->left != NULL) postOrder(root->left);
            if (root->right != NULL) postOrder(root->right);
            cout << root->val << " ";
        }
    }

};

void main()
{
    AVLtree avl;
    int choice,val;

    do {
        cout << "\n1. Insert\n";
        cout << "2. PreOrder\n";
        cout << "3. InOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Value to Insert : ";
            cin >> val;
            avl.insert(val);
        }

        else if (choice == 2)
        {
            avl.preOrder(avl.root);
        }
        else if (choice == 3)
        {
            avl.InOrder(avl.root);
        }
        else if (choice == 4)
        {
            avl.postOrder(avl.root);
        }
        else if (choice == 5)
        {
            cout<<"Exiting.."<<endl;
        }
        
    } while (choice != 5);
    
}*/


#include<iostream>
#include<algorithm>
using namespace std;

class AVLtree
{
public:
    struct Node
    {
        int val;
        Node* left;
        Node* right;
        int height;

        Node(int v)
        {
            val = v;
            left = NULL;
            right = NULL;
            height = 1;
        }
    };

    Node* root;

    int height(Node* n)
    {
        if (n != NULL)
        {
            return n->height;
        }
        else
        {
            return 0;
        }
    }

    int balancefactor(Node* n)
    {
        if (n != NULL)
        {
            return height(n->left) - height(n->right);
        }
        else
        {
            return 0;
        }
    }

    AVLtree()
    {
        root = NULL;
    }

    void rotateright(Node*& y)
    {
        Node* x = y->left;
        Node* T = x->right;

        x->right = y;
        y->left = T;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        y = x;
    }

    void rotateleft(Node*& x)
    {
        Node* y = x->right;
        Node* T = y->left;

        y->left = x;
        x->right = T;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        x = y;
    }

    void insert(Node*& node, int val)
    {
        if (node == NULL)
        {
            node = new Node(val);
            return;
        }

        if (val > node->val)
        {
            insert(node->right, val);
        }
        else if (val < node->val)
        {
            insert(node->left, val);
        }
        else
        {
            return;
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balancefactor(node);
        //left left case
        if (balance > 1 && val < node->left->val)
        {
            rotateright(node);
        }

        //right right case
        if (balance < -1 && val > node->right->val)
        {
            rotateleft(node);
        }

        //left right case
        if (balance > 1 && val > node->left->val)
        {
            rotateleft(node->left);
            rotateright(node);
        }
        //right left case
        if (balance < -1 && val < node->right->val)
        {
            rotateright(node->right);
            rotateleft(node);
        }
    }

    void insert(int val)
    {
        insert(root, val);
    }

    void remove(int v)
    {
        if (root == NULL)
        {
            cout << "Tree is Empty." << endl;
            return;
        }
        Node* curr = root;
        Node* parent = NULL;

        while (curr != NULL && curr->val != v)
        {
            parent = curr;
            if (v < curr->val)
            {
                curr = curr->left;
            }
            else if (v > curr->val)
            {
                curr = curr->right;
            }
        }

        if (curr == NULL)
        {
            cout << v << " not found in the Tree." << endl;
            return;
        }

        if (curr->left == NULL && curr->right == NULL)
        {
            if (curr == root)
            {
                root = NULL;
            }
            else if (parent->left == curr)
            {
                parent->left = NULL;
            }
            else if (parent->right == curr)
            {
                parent->right = NULL;
            }
            delete curr;
        }
        else if (curr->left == NULL || curr->right == NULL)
        {
            Node* child;
            if (curr->right != NULL)
            {
                child = curr->right;
            }
            else
            {
                child = curr->left;
            }

            if (curr == root)
            {
                root = child;
            }
            else if (parent->left == curr)
            {
                parent->left = child;
            }
            else if (parent->right == curr)
            {
                parent->right = child;
            }
            delete curr;
        }
        else
        {
            Node* successor = curr->right;
            Node* successorParent = curr;

            while (successor->left != NULL)
            {
                successorParent = successor;
                successor = successor->left;
            }

            curr->val = successor->val;

            if (successorParent->left == successor)
            {
                successorParent->left = successor->right;
            }
            else
            {
                successorParent->right = successor->right;
            }
            delete successor;
        }

        root = balanceTree(root);

        cout << v << " removed from the Tree." << endl;
    }

    Node* balanceTree(Node* node)
    {
        if (node == NULL) return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balancefactor(node);

        // Left Left Case
        if (balance > 1 && balancefactor(node->left) >= 0)
            rotateright(node);

        // Left Right Case
        if (balance > 1 && balancefactor(node->left) < 0)
        {
            rotateleft(node->left);
            rotateright(node);
        }

        // Right Right Case
        if (balance < -1 && balancefactor(node->right) <= 0)
            rotateleft(node);

        // Right Left Case
        if (balance < -1 && balancefactor(node->right) > 0)
        {
            rotateright(node->right);
            rotateleft(node);
        }

        return node;
    }

    void preOrder(Node* root)
    {
        if (root != NULL)
        {
            cout << root->val << " ";
            if (root->left != NULL) preOrder(root->left);
            if (root->right != NULL) preOrder(root->right);
        }
    }

    void InOrder(Node* r)
    {
        cout << "Data : ";
        if (r != NULL)
        {
            if (r->left != NULL) InOrder(r->left);
            cout << r->val << " ";
            if (r->right != NULL) InOrder(r->right);
        }
    }

    void postOrder(Node* root)
    {
        cout << "Data : ";
        if (root != NULL)
        {
            if (root->left != NULL) postOrder(root->left);
            if (root->right != NULL) postOrder(root->right);
            cout << root->val << " ";
        }
    }

};

int main()
{
    AVLtree avl;
    int choice, val;

    do {
        cout << "\n1. Insert\n";
        cout << "2. PreOrder\n";
        cout << "3. InOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Delete Node\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Value to Insert : ";
            cin >> val;
            avl.insert(val);
        }

        else if (choice == 2)
        {
            avl.preOrder(avl.root);
        }
        else if (choice == 3)
        {
            avl.InOrder(avl.root);
        }
        else if (choice == 4)
        {
            avl.postOrder(avl.root);
        }
        else if (choice == 5)
        {
            cout << "Enter Value to Delete : ";
            cin >> val;
            avl.remove(val);
        }
        else if (choice == 6)
        {
            cout << "Exiting.." << endl;
        }

    } while (choice != 6);

    return 0;
}
