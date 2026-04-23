#include<iostream>
#include<string>
using namespace std;

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
