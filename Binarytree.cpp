/*#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;

};

/*Node* insert(Node* root, int val)
{
	if (root == NULL)
	{
		return new Node(val);
	}
	if (val < root->data)
	{
		root->left = insert(root->left, val);
	}
	else
	{
		root->right = insert(root->right, val);
	}
	return root;
}*/

/*void insert(Node*& root, int val)
{
	Node* t = new Node;
	Node* parent;
	t->data = val;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	if (root == NULL)
	{
		root = t;
	}
	else
	{
		Node* curr;
		curr = root;
		while (curr != NULL)
		{
			parent = curr;
			if (t->data > curr->data)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}
		if (t->data < parent->data)
		{
			parent->left = t;
		}
		else
		{
			parent->right = t;
		}
	}
}

void inorder(Node* root)
{
	if (root != NULL)
	{
		if (root->left)
		{
			inorder(root->left);
		}
		cout << " " << root->data << " ";
		if (root->right) inorder(root->right);
	}
	else return;
}

int main()
{
	Node* root=NULL;
	insert(root, 5);
	insert(root, 3);
	insert(root, 2);
	insert(root, 7);
	insert(root, 1);

	inorder(root);
}*/

//Walkthrough
/*#include<iostream>
#include<cstdlib>
using namespace std;

class BST
{
private:
	struct treeNode {
		treeNode* left;
		treeNode* right;
		int data;
	};
	treeNode* root;
public:
	BST()
	{
		root = NULL;
	}
	bool isEmpty()
	{
		return root == NULL;
	}
	void Insert(int d)
	{
		treeNode* t = new treeNode;
		treeNode* parent;
		t->data = d;
		t->left = NULL;
		t->right = NULL;
		parent = NULL;

		if (isEmpty())
		{
			root = t;
		}
		else
		{
			treeNode* curr;
			curr = root;
			while (curr != NULL)
			{
				parent = curr;
				if (t->data > curr->data)
				{
					curr = curr->right;
				}
				else
				{
					curr = curr->left;
				}
			}
			if (t->data > parent->data)
			{
				parent->right = t;
			}
			else
			{
				parent->left = t;
			}
		}
	}

	void remove(int d)
	{
		bool found = false;
		if (isEmpty())
		{
			cout << "Tree is Empty." << endl;
			return;
		}
		treeNode* curr;
		treeNode* parent=NULL;
		curr = root;

		while (curr != NULL)
		{
			if (curr->data == d)
			{
				found = true;
				break;
			}
			else
			{
				parent = curr;
				if (d > curr->data) 
				{
					curr = curr->right;
				}
				else
				{
					curr = curr->left;
				}
			}
		}
		if (!found)
		{
			cout << "Data Not Found." << endl;
			return;
		}

		//Node with Single Child
		if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL))
		{
			if (curr->left == NULL && curr->right != NULL)
			{
				if (parent->left == curr)
				{
					parent->left = curr->right;
					delete curr;
				}
				else
				{
					parent->right = curr->right;
					delete curr;
				}
			}
			else // left child present, right child is not.
			{
				if (parent->left == curr)
				{
					parent->left = curr->left;
					delete curr;
				}
				else
				{
					parent->right = curr->left;
					delete curr;
				}
			}
			return;
		}

		//for leaf Node
		if (curr->left == NULL && curr->right == NULL)
		{
			if (parent->left == curr)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
			delete curr;
			return;
		}

		//Node with 2 children
		if (curr->left != NULL && curr->right != NULL)
		{
			treeNode* chkr;
			chkr = curr->right;
			if ((chkr->left == NULL) && (chkr->right == NULL))
			{
				curr = chkr;
				delete chkr;
				curr->right = NULL;
			}
			else // right child has children
			{ 
				if ((curr->right)->left != NULL)
				{
					treeNode* lcurr;
					treeNode* lcurrp;
					lcurrp = curr->right;
					lcurr = (curr->right)->left;
					while (lcurr->left != NULL)
					{
						lcurrp = lcurr;
						lcurr = lcurr->left;
					}
					curr->data = lcurr->data;
					delete lcurr;
					lcurrp->left = NULL;
				}
				else
				{
					treeNode* tmp;
					tmp = curr->right;
					curr->data = tmp->data;
					curr->right = tmp->right;
					delete tmp;
				}
			}
			return;
		}
	}

	void print_inorder()
	{
		inorder(root);
	}

	void inorder(treeNode* p)
	{
		if (p != NULL)
		{
			if (p->left != NULL) inorder(p->left);
			cout << " " << p->data << " ";
			if (p->right != NULL) inorder(p->right);
		}
		else return;
	}

	void print_preorder()
	{
		preorder(root);
	}

	void preorder(treeNode* p)
	{
		if (p != NULL)
		{
			cout << " " << p->data << " ";
			if (p->left != NULL) preorder(p->left);
			if (p->right != NULL) preorder(p->right);
		}
		else return;
	}

	void print_postorder()
	{
		postorder(root);
	}

	void postorder(treeNode* p)
	{
		if (p != NULL)
		{
			if (p->left != NULL) postorder(p->left);
			if (p->right != NULL) postorder(p->right);
			cout << " " << p->data << " ";
		}
		else return;
	}
};

int main()
{
	BST b;
	int ch, tmp, tmp1;
	while (1)
	{
		cout << endl << endl;
		cout << "Binary Search Tree Operations " << endl;
		cout << "--------------------------------" << endl;
		cout << "1. Insertion " << endl;
		cout << "2. In-Order Traversal " << endl;
		cout << "3. Pre-Order Traversal " << endl;
		cout << "4. Post-Order Traversal " << endl;
		cout << "5. Removal " << endl;
		cout << "6. Exit." << endl;
		cout << "Enter Your Choice : ";
		cin >> ch;

		switch (ch)
		{
		case 1: cout << "Enter Number to be Inserted : ";
			cin >> tmp;
			b.Insert(tmp);
			break;
		case 2: cout << endl;
			cout << "In-Order Traversal " << endl;
			cout << "---------------------" << endl;
			b.print_inorder();
			break;
		case 3: cout << endl;
			cout << "Pre-Order Traversal " << endl;
			cout << "----------------------" << endl;
			b.print_preorder();
			break;
		case 4:cout << endl;
			cout << "Post-Order Traversal " << endl;
			cout << "-----------------------" << endl;
			b.print_postorder();
			break;
		case 5: cout << "Enter data to be deleted : ";
			cin >> tmp1;
			b.remove(tmp1);
			break;
		case 6: 
			return 0;
		}
	}
}*/



//PT 1 and 2

/*#include <iostream>
#include <cstdlib>
using namespace std;

class BST
{
private:
	struct treeNode {
		treeNode* left;
		treeNode* right;
		int data;
	};
	treeNode* root;

	// Helper function for recursive search
	bool searchRecursive(treeNode* node, int key)
	{
		if (node == NULL)
			return false; // Not found
		if (node->data == key)
			return true; // Found
		else if (key < node->data)
			return searchRecursive(node->left, key); // Search in left subtree
		else
			return searchRecursive(node->right, key); // Search in right subtree
	}

	// Helper function for Display_less
	void displayLessHelper(treeNode* node, int number)
	{
		if (node == NULL)
			return;

		// Check the left subtree
		displayLessHelper(node->left, number);

		// Process the current node if it satisfies the condition
		if (node->data <= number)
			cout << node->data << " ";

		// Check the right subtree
		displayLessHelper(node->right, number);
	}

public:
	BST()
	{
		root = NULL;
	}
	bool isEmpty()
	{
		return root == NULL;
	}
	void Insert(int d)
	{
		treeNode* t = new treeNode;
		treeNode* parent;
		t->data = d;
		t->left = NULL;
		t->right = NULL;
		parent = NULL;

		if (isEmpty())
		{
			root = t;
		}
		else
		{
			treeNode* curr;
			curr = root;
			while (curr != NULL)
			{
				parent = curr;
				if (t->data > curr->data)
				{
					curr = curr->right;
				}
				else
				{
					curr = curr->left;
				}
			}
			if (t->data > parent->data)
			{
				parent->right = t;
			}
			else
			{
				parent->left = t;
			}
		}
	}

	void print_inorder()
	{
		inorder(root);
	}

	void inorder(treeNode* p)
	{
		if (p != NULL)
		{
			if (p->left != NULL) inorder(p->left);
			cout << " " << p->data << " ";
			if (p->right != NULL) inorder(p->right);
		}
		else return;
	}

	void print_preorder()
	{
		preorder(root);
	}

	void preorder(treeNode* p)
	{
		if (p != NULL)
		{
			cout << " " << p->data << " ";
			if (p->left != NULL) preorder(p->left);
			if (p->right != NULL) preorder(p->right);
		}
		else return;
	}

	void print_postorder()
	{
		postorder(root);
	}

	void postorder(treeNode* p)
	{
		if (p != NULL)
		{
			if (p->left != NULL) postorder(p->left);
			if (p->right != NULL) postorder(p->right);
			cout << " " << p->data << " ";
		}
		else return;
	}

	// Recursive Search
	bool search(int key)
	{
		return searchRecursive(root, key);
	}

	// Display elements less than or equal to the given number
	void Display_less()
	{
		int number;
		cout << "Enter a number to find elements less than or equal to it: ";
		cin >> number;
		cout << "Elements less than or equal to " << number << " are: ";
		displayLessHelper(root, number);
		cout << endl;
	}
};

int main()
{
	BST b;
	int value;

	cout << "Enter values to insert into the BST (Enter a negative number to stop):" << endl;
	while (true)
	{
		cin >> value;
		if (value < 0)
			break;
		b.Insert(value);
	}

	cout << endl << "In-Order Traversal:" << endl;
	b.print_inorder();

	cout << endl << "Pre-Order Traversal:" << endl;
	b.print_preorder();

	cout << endl << "Post-Order Traversal:" << endl;
	b.print_postorder();

	cout << endl;
	b.Display_less(); // Call Display_less function to show relevant elements

	cout << endl << "Enter a value to search in the BST: ";
	cin >> value;

	if (b.search(value))
		cout << value << " is found in the BST." << endl;
	else
		cout << value << " is not found in the BST." << endl;

	return 0;
}*/



/*#include<iostream>
#include<cstdlib>
using namespace std;

class BST
{
private:
	struct treeNode {
		treeNode* left;
		treeNode* right;
		int data;
	};
	treeNode* root;
public:
	BST()
	{
		root = NULL;
	}
	bool isEmpty()
	{
		return root == NULL;
	}
	void Insert(int d)
	{
		treeNode* t = new treeNode;
		treeNode* parent;
		t->data = d;
		t->left = NULL;
		t->right = NULL;
		parent = NULL;

		if (isEmpty())
		{
			root = t;
		}
		else
		{
			treeNode* curr;
			curr = root;
			while (curr != NULL)
			{
				parent = curr;
				if (t->data > curr->data)
				{
				   curr = curr->right;
				}
				else
				{
					curr = curr->left;
				}
			}
			if (t->data > parent->data)
			{
				parent->right = t;
			}
			else
			{
				parent->left = t;
			}
		}
	}

	void remove(int d)
	{
		bool found = false;
		if (isEmpty())
		{
			cout << "Tree is Empty." << endl;
			return;
		}
		treeNode* curr;
		treeNode* parent = NULL;
		curr = root;

		while (curr != NULL)
		{
			if (curr->data == d)
			{
				found = true;
				break;
			}
			else
			{
				parent = curr;
				if (d > curr->data)
				{
					curr = curr->right;
				}
				else
				{
					curr = curr->left;
				}
			}
		}
		if (!found)
		{
			cout << "Data Not Found." << endl;
			return;
		}

		//Node with one child
		if ((curr->right == NULL && curr->left != NULL) || (curr->right != NULL && curr->left == NULL))
		{
			if (curr->right == NULL && curr->left != NULL)// if the node has left child.
			{
				if (parent->right == curr)
				{
					parent->right = curr->left;
					delete curr;
				}
				else
				{
					parent->left = curr->left;
					delete curr;
				}
			}
			else  // if the node has right child
			{
				if (parent->right == curr)
				{
					parent->right = curr->right;
					delete curr;
				}
				else
				{
					parent->left = curr->right;
					delete curr;
				}
			}
			return;
		}

		// Leaf Node
		if (curr->left == NULL && curr->right == NULL)
		{
			if (parent->left == curr)
			{
				parent->left = NULL;
				delete curr;
			}
			else
			{
				parent->right = NULL;
				delete curr;
			}
			return;
		}


		// if Node have both left and right Nodes

		if (curr->left != NULL && curr->right != NULL)
		{
			treeNode* chkr;
			chkr = curr->right;
			if (chkr->right == NULL && chkr->left == NULL)
			{
				curr = chkr;
				delete chkr;
				curr->right = NULL;
			}
			else
			{
				if ((curr->right)->left != NULL)
				{
					treeNode* lcurr;
					treeNode* lcurrp;
					lcurr = (curr->right)->left;
					lcurrp = curr->right;
					while (lcurr->left != NULL)
					{
						lcurrp = lcurr;
						lcurr = lcurr->left;
					}
					curr->data = lcurr->data;
					delete lcurr;
					lcurrp->left = NULL;
				}
				else
				{
					treeNode* temp;
					temp = curr->right;
					curr->data = temp->data;
					curr->right = temp->right;
					delete temp;
				}
			}
			return;
		}
	}
	void print_inorder()
	{
		inorder(root);
	}

	void inorder(treeNode* p)
	{
		if (p != NULL)
		{
			if (p->left != NULL) inorder(p->left);
			cout << " " << p->data << " ";
			if (p->right != NULL) inorder(p->right);
		}
		else return;
	}

	void print_preorder()
	{
		preorder(root);
	}

	void preorder(treeNode* p)
	{
		if (p != NULL)
		{
			cout << " " << p->data << " ";
			if (p->left != NULL) preorder(p->left);
			if (p->right != NULL) preorder(p->right);
		}
		else return;
	}

	void print_postorder()
	{
		postorder(root);
	}

	void postorder(treeNode* p)
	{
		if (p != NULL)
		{
			if (p->left != NULL) postorder(p->left);
			if (p->right != NULL) postorder(p->right);
			cout << " " << p->data << " ";
		}
		else return;
	}
};

int main()
{
	BST b;
	int ch, tmp, tmp1;
	while (1)
	{
		cout << endl << endl;
		cout << "Binary Search Tree Operations " << endl;
		cout << "--------------------------------" << endl;
		cout << "1. Insertion " << endl;
		cout << "2. In-Order Traversal " << endl;
		cout << "3. Pre-Order Traversal " << endl;
		cout << "4. Post-Order Traversal " << endl;
		cout << "5. Removal " << endl;
		cout << "6. Exit." << endl;
		cout << "Enter Your Choice : ";
		cin >> ch;

		switch (ch)
		{
		case 1: cout << "Enter Number to be Inserted : ";
			cin >> tmp;
			b.Insert(tmp);
			break;
		case 2: cout << endl;
			cout << "In-Order Traversal " << endl;
			cout << "---------------------" << endl;
			b.print_inorder();
			break;
		case 3: cout << endl;
			cout << "Pre-Order Traversal " << endl;
			cout << "----------------------" << endl;
			b.print_preorder();
			break;
		case 4:cout << endl;
			cout << "Post-Order Traversal " << endl;
			cout << "-----------------------" << endl;
			b.print_postorder();
			break;
		case 5: cout << "Enter data to be deleted : ";
			cin >> tmp1;
			b.remove(tmp1);
			break;
		case 6:
			return 0;
		}
	}
}*/

#include<iostream>
#include<string>
using namespace std;

/*struct Record
{
	int record_id;
	string name;
	int age;
	string address;
};

class BST
{
private:
	struct treeNode
	{
		Record data;
		treeNode* left;
		treeNode* right;
	};
public:
	

	treeNode* root;
	
	BST()
	{
		root = NULL;
	}

	bool isEmpty()
	{
		return root == NULL;
	}

	void insert(Record r)
	{
		treeNode* t = new treeNode;
		treeNode* parent;
		t->data = r;
		t->left = NULL;
		t->right = NULL;
		parent = NULL;

		if (isEmpty())
		{
			root = t;
			return;
		}
		else
		{
			treeNode* curr;
			curr = root;
			while (curr != NULL)
			{
				parent = curr;
				if (t->data.record_id > curr->data.record_id)
				{
					curr = curr->right;
				}
				else if(t->data.record_id<curr->data.record_id)
				{
					curr = curr->left;
				}
			}
			if (t->data.record_id > parent->data.record_id)
			{
				parent->right = t;
			}
			else if(t->data.record_id<parent->data.record_id)
			{
				parent->left = t;
			}
		}
	}

	bool search(treeNode* r,int r_id)
	{
		bool found = false;
		if (r==NULL)
		{
			return found;
		}

		if (r->data.record_id == r_id)
		{
			found = true;
			return found;
		}

		if (r_id > r->data.record_id)
		{
			return search(r->right,r_id);
		}

		if (r_id < r->data.record_id)
		{
			return search(r->left, r_id);
		}

		if (!found)
		{
			cout << "Record Not Found with Record Id : " << r_id;
		}
	}

	void remove(int r_id)
	{
		if (isEmpty())
		{
			cout << "Tree is Empty." << endl;
			return;
		}

		treeNode* curr = root;
		treeNode* parent = NULL;

		// Find the node to remove
		while (curr != NULL && curr->data.record_id != r_id)
		{
			parent = curr;
			if (r_id > curr->data.record_id)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}

		if (curr == NULL)
		{
			cout << "Data Not Found." << endl;
			return;
		}

		// Case 1: Node with no children (leaf node)
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
			else
			{
				parent->right = NULL;
			}
			delete curr;
		}
		// Case 2: Node with one child
		else if (curr->left == NULL || curr->right == NULL)
		{
			treeNode* child = (curr->left != NULL) ? curr->left : curr->right;

			if (curr == root)
			{
				root = child;
			}
			else if (parent->left == curr)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
			delete curr;
		}
		// Case 3: Node with two children
		else
		{
			treeNode* successor = curr->right;
			treeNode* successorParent = curr;

			// Find the in-order successor (leftmost node in right subtree)
			while (successor->left != NULL)
			{
				successorParent = successor;
				successor = successor->left;
			}

			// Replace current node's data with successor's data
			curr->data = successor->data;

			// Delete the successor node
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

		cout << "Record with Record ID " << r_id << " removed successfully." << endl;
	}


	void preOrder(treeNode* r)
	{
		if (r != NULL)
		{
			cout << "Record ID : " << r->data.record_id << ", Name : " << r->data.name << ", Age : " << r->data.age << ", Address : " << r->data.address<<"."<<endl;
			if (r->left != NULL)
			{
				preOrder(r->left);
			}
			if (r->right != NULL)
			{
				preOrder(r->right);
			}
		}
	}

	void inOrder(treeNode* r)
	{
		if (r != NULL)
		{
			if (r->left != NULL)
			{
				inOrder(r->left);
			}
			cout << "Record ID : " << r->data.record_id << ", Name : " << r->data.name << ", Age : " << r->data.age << ", Address : " << r->data.address << "."<<endl;
			if (r->right != NULL)
			{
				inOrder(r->right);
			}
		}
	}

	void postOrder(treeNode* r)
	{
		if (r != NULL)
		{
			if (r->left != NULL)
			{
				postOrder(r->left);
			}
			if (r->right != NULL)
			{
				postOrder(r->right);
			}
			cout << "Record ID : " << r->data.record_id << ", Name : " << r->data.name << ", Age : " << r->data.age << ", Address : " << r->data.address << "."<<endl;
		}
	}
};


void main()
{
	BST r_tree;
	int choice;
	do {
		cout << "\n1.Insert." << endl;
		cout << "2.Search." << endl;
		cout << "3.Remove." << endl;
		cout << "4.Print PreOrder." << endl;
		cout << "5.Print InOrder." << endl;
		cout << "6.Print PreOrder." << endl;
		cout << "7.Exit." << endl;
		cout << "Enter Choice : ";
		cin >> choice;

		if (choice == 1)
		{
			Record r;
			cout << "Enter Record ID : ";
			cin >> r.record_id;
			cout << "Enter Name : ";
			cin.ignore();
			getline(cin, r.name);
			cout << "Enter Age : ";
			cin >> r.age;
			cout << "Enter Address : ";
			cin.ignore();
			getline(cin, r.address);
			r_tree.insert(r);
			cout << "Inserted Successfully." << endl;
		}

		else if (choice == 2)
		{
			int r_id;
			cout << "Enter Record ID to Search : ";
			cin >> r_id;
			if (r_tree.search(r_tree.root, r_id) == true)
			{
				cout << "Record with Record ID  " << r_id << " found." << endl;
			}
			else
			{
				cout << "Record with Record ID  " << r_id << " not found." << endl;
			}
		}

		else if (choice == 3)
		{
			int r_id;
			cout << "Enter Record ID to remove : ";
			cin >> r_id;
			r_tree.remove(r_id);
		}

		else if (choice == 4)
		{
			r_tree.preOrder(r_tree.root);
		}

		else if (choice == 5)
		{
			r_tree.inOrder(r_tree.root);
		}

		else if (choice == 6)
		{
			r_tree.postOrder(r_tree.root);
		}
		
		else if (choice == 7)
		{
			cout << "Exiting..." << endl;
		}

		else
		{
			cout << "Invalid Choice!" << endl;
		}

	} while (choice != 7);
}*/

/*class BST
{
public:
	struct treeNode
	{
		int data;
		treeNode* right;
		treeNode* left;
	};
	treeNode* root;

	BST()
	{
		root = NULL;
	}

	void insert(int d)
	{
		treeNode* t = new treeNode;
		treeNode* parent=NULL;
		t->data = d;
		t->left = NULL;
		t->right = NULL;

		if (root == NULL)
		{
			root = t;
			return;
		}
		else
		{
			treeNode* curr = root;
			while (curr != NULL)
			{
				parent = curr;
				if (d > curr->data)
				{
					curr = curr->right;
				}
				else
				{
					curr = curr->left;
				}
			}
			if (d > parent->data)
			{
				parent->right = t;
			}
			else if(d < parent->data)
			{
				parent->left = t;
			}
			else
			{
				return;
			}
		}
	}

	bool Search(treeNode* curr,int d)
	{
		if (curr == NULL)
		{
			return false;
		}
		
	    if (d == curr->data)
		{
				return true;
		}
		if (d > curr->data)
		{
				return Search(curr->right, d);
		}
		if (d < curr->data)
		{
				return Search(curr->left, d);
		}
	}

	void remove(int d)
	{
		if (root == NULL)
		{
			cout << "Tree is Empty." << endl;
			return;
		}

		treeNode* curr = root;
		treeNode* parent = NULL;

		while (curr != NULL && curr->data != d)
		{
			parent = curr;
			if (d > curr->data)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}

		if (curr == NULL)
		{
			cout << d << " not found in the tree." << endl;
			return;
		}

		if (curr->right == NULL && curr->left == NULL)
		{
			if (curr == root)
			{
				root = NULL;
			}
			if (parent->right == curr)
			{
				parent->right = NULL;
			}
			else
			{
				parent->left = NULL;
			}
			delete curr;
			return;
		}
		
		if ((curr->right == NULL && curr->left != NULL) || (curr->right != NULL && curr->left == NULL))
		{
			if (curr->right == NULL && curr->left != NULL)
			{
				if (parent->right == curr)
				{
					parent->right = curr->left;
				}
				else
				{
					parent->left = curr->left;
				}
				delete curr;
			}
			else if (curr->right!=NULL && curr->left==NULL)
			{
				if (parent->right == curr)
				{
					parent->right = curr->right;
				}
				else
				{
					parent->left = curr->right;
				}
				delete curr;
			}
			return;
		}

		if (curr->right != NULL && curr->left != NULL)
		{
			treeNode* successor = curr->right;
			treeNode* successorP = curr;

			while (successor->left != NULL)
			{
				successorP = successor;
				successor = successor->left;
			}

			curr->data = successor->data;

			if (successorP->left == successor)
			{
				successorP->left = successor->right;
			}
			else
			{
				successorP->right = successor->right;
			}
			delete successor;
			return;
		}
	}

	void preorder(treeNode* r)
	{
		if (r != NULL)
		{
			cout << r->data << " ";
			if(r->left != NULL) preorder(r->left);
			if(r->right != NULL) preorder(r->right);
		}
	}

	void inorder(treeNode* r)
	{
		if (r != NULL)
		{
			if (r->left != NULL) preorder(r->left);
			cout << r->data << " ";
			if (r->right != NULL) preorder(r->right);
		}
	}

	void postorder(treeNode* r)
	{
		if (r != NULL)
		{
			if (r->left != NULL) preorder(r->left);
			if (r->right != NULL) preorder(r->right);
			cout << r->data << " ";
		}
	}
};

int main()
{
	int choice;
	BST bst;
	do {
		cout << "\n1. Insert\n";
		cout << "2. Search\n";
		cout << "3. Remove\n";
		cout << "4. preOrder.\n";
		cout << "5. InOrder.\n";
		cout << "6. postOrder.\n";
		cout << "7. Exit.\n";
		cout << "Enter Your Choice : ";
		cin >> choice;

		if (choice == 1)
		{
			int val;
			cout << "Enter Value to Insert : ";
			cin >> val;
			bst.insert(val);
		}
		else if (choice == 2)
		{
			int val;
			cout << "Enter Value to Search : ";
			cin >> val;
			if(bst.Search(bst.root, val) == true)
			{
				cout << val << " Found in the Tree." << endl;
			}
			else
			{
				cout << val << " not Found in the Tree." << endl;
			}
		}
		else if (choice == 3)
		{
			int val;
			cout << "Enter Value to Remove : ";
			cin >> val;
			bst.remove(val);
		}
		else if (choice == 4)
		{
			bst.preorder(bst.root);
		}
		else if (choice == 5)
		{
			bst.inorder(bst.root);
		}
		else if (choice == 6)
		{
			bst.postorder(bst.root);
		}
		else if (choice == 7)
		{
			cout << "Exiting.." << endl;
		}
	} while (choice != 7);

	return 0;
}*/

class BST
{
public:
	struct treeNode
	{
		int val;
		treeNode* left;
		treeNode* right;
	};

	treeNode* root;
	BST()
	{
		root = NULL;
	}
	~BST()
	{
	}
	void insert(int v)
	{
		treeNode* newNode=new treeNode;
		treeNode* Nodeptr;
		newNode->val = v;
		newNode->left = NULL;
		newNode->right = NULL;

		if (root == NULL)
		{
			root = newNode;
		}

		else
		{
			Nodeptr = root;
			while (Nodeptr != NULL)
			{
				if (v < Nodeptr->val)
				{
					if (Nodeptr->left != NULL)
					{
						Nodeptr = Nodeptr->left;
					}
					else
					{
						Nodeptr->left = newNode;
						break;
					}
				}
				else if (v > Nodeptr->val)
				{
					if (Nodeptr->right != NULL)
					{
						Nodeptr = Nodeptr->right;
					}
					else
					{
						Nodeptr->right = newNode;
						break;
					}
				}
				else
				{
					cout << "Duplicate Value found in the tree.\n";
					break;
				}
			}
		}
	}

	bool find(int v)
	{
		treeNode* Nodeptr = root;

		while (Nodeptr != NULL)
		{
			if (v == Nodeptr->val)
			{
				return true;
			}
			else if (v > Nodeptr->val)
			{
				Nodeptr = Nodeptr->right;
			}
			else
			{
				Nodeptr = Nodeptr->left;
			}
		}
		return false;
	}

	void preorder(treeNode* t)
	{
		if (t != NULL)
		{
			cout << t->val << " ";
			if (t->left != NULL) preorder(t->left);
			if (t->right != NULL) preorder(t->right);
		}
		else
		{
			cout << "Tree is Empty." << endl;
		}
	}

	void postorder(treeNode* t)
	{
		if (t != NULL)
		{
			if (t->left != NULL) postorder(t->left);
			if (t->right != NULL) postorder(t->right);
			cout << t->val << " ";
		}
		else
		{
			cout << "Tree is Empty." << endl;
		}
	}

	void inorder(treeNode* t)
	{
		if (t != NULL)
		{
			if (t->left != NULL) inorder(t->left);
			cout << t->val << " ";
			if (t->right != NULL) inorder(t->right);
		}
		else
		{
			cout << "Tree is Empty." << endl;
		}
	}
	
	void remove(int v)
	{

		if (root == NULL)
		{
			cout << "Tree is Empty." << endl;
			return;
		}
		treeNode* curr = root;
		treeNode* parent = NULL;

		while (curr != NULL && curr->val != v)
		{
			parent = curr;
			if (v < curr->val)
			{
				curr = curr->left;
			}
			else if(v > curr->val)
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
			treeNode* child;
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
			treeNode* successor = curr->right;
			treeNode* successorParent = curr;

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
		cout << v << " removed from the Tree." << endl;
	}


};


int main()
{
	BST tree;
	cout << "Inserting Nodes : ";
	tree.insert(5);
	tree.insert(8);
	tree.insert(3);
	tree.insert(12);
	tree.insert(9);
	if (tree.find(56))
	{
		cout << "56 found in the Tree." << endl;
	}
	else
	{
		cout << "56 Not found in the Tree" << endl;
	}
	cout << "Inorder : ";
	tree.inorder(tree.root);
	cout << endl;
	cout << "Preorder : ";
	tree.preorder(tree.root);
	cout << endl;
	cout << "Postorder : ";
	tree.postorder(tree.root);
	cout << endl;
	tree.remove(5);
	cout << "Inorder : ";
	tree.inorder(tree.root);
	cout << endl;
	return 0;
}