#include<iostream>
using namespace std;
//Simple function only LinkedList
/*class Node {
public:
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

void InsertatTail(Node* &head, int val)
{
	Node* n = new Node(val);

	if (head == NULL)
	{
		head = n;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
}

void InsertatHead(Node*& head, int val)
{
	Node* n = new Node(val);
	n->next = head;
	head = n;
}

void ll.display(Node* head)
{
	while (head != NULL)
	{
		cout << head->data << "->";
		head = head->next;
	}
	cout <<"NULL"<< endl;
}

bool Search(Node* head, int key)
{
	while (head->next != NULL)
	{
		if (head->data == key)
		{
			return true;
		}
		head = head->next;
	}
	return false;
}


void deleteathead(Node*& head)
{
	Node* deletednode = head;
	head = head->next;

	delete deletednode;
}

void ll.deletion(Node*& head, int val)
{
	if (head == NULL)
	{
		cout << "linked List is Empry." << endl;
		return;
	}
	if (head->next == NULL)
	{
		deleteathead(head);
		return;
	}

	Node* temp = head;
	while (temp->next!=NULL && temp->next->data != val)
	{
		temp=temp->next;
	}
	if (temp->next == NULL)
	{
		cout << "Value" << val << "not found in the List." << endl;
		return;
	}
	Node* deletednode = temp->next;
	temp->next = temp->next->next;
	
	delete deletednode;
}

int main()
{
	Node* head=NULL;
	InsertatTail(head, 1);
	InsertatTail(head, 3);
	InsertatTail(head, 5);
	InsertatHead(head, 56);
	ll.display(head);
	cout << endl << Search(head, 56);
	cout << endl << Search(head, 17);
	ll.deletion(head, 1);
	ll.display(head);
	ll.deletion(head,3);
	ll.display(head);
	deleteathead(head);
	ll.display(head);
	return 0;
}*/
// Class of Linked List Also
/*class Node {
public:
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};
class LinkedList
{
private:
	Node* head = NULL;
public:
void InsertatTail(int val)
{
	Node* n = new Node(val);

	if (head == NULL)
	{
		head = n;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
}

void InsertatHead(int val)
{
	Node* n = new Node(val);
	n->next = head;
	head = n;
}

void display()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

bool Search(int key)
{
	Node* currNode = head;
	while (currNode->next != NULL)
	{
		if (currNode->data == key)
		{
			return true;
		}
		currNode = currNode->next;
	}
	return false;
}


void deleteathead()
{
	Node* deletednode = head;
	head = head->next;

	delete deletednode;
}

void deletion(int val)
{
	if (head == NULL)
	{
		cout << "linked List is Empry." << endl;
		return;
	}
	if (head->next == NULL)
	{
		deleteathead();
		return;
	}

	Node* temp = head;
	while (temp->next != NULL && temp->next->data != val)
	{
		temp = temp->next;
	}
	if (temp->next == NULL)
	{
		cout << "Value" << val << "not found in the List." << endl;
		return;
	}
	Node* deletednode = temp->next;
	temp->next = temp->next->next;

	delete deletednode;
}

void InsertinMiddle(int index, int x)
{
	if (index < 0)
	{
		cout << "Index cannot be negative." << endl;
		return;
	}

	// Special case: Insert at the head
	if (index == 0)
	{
	  InsertatHead(x);
	  return;
	}

	int currIndex = 1; // Start at index 1, assuming the first node is index 0
	Node* currNode = head;

	// Traverse to the node just before the insertion point
	while (currNode != NULL && currIndex < index)
	{
		currNode = currNode->next;
		currIndex++;
	}

	// If the index is out of bounds
	if (currNode == NULL)
	{
		cout << "Index out of bounds." << endl;
		return;
	}

	// Create the new node and insert it
	Node* newNode = new Node(x);
	newNode->next = currNode->next;
	currNode->next = newNode;

}
};*/
//Practice Again of Linked List using Class.
/*class Node
{
public:
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

class LinkedList
{
	
public:
	Node* head = NULL;
	void InsertatHead(int val)
	{
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}
	void InsertatTail(int val)
	{
		if (head == NULL)
		{
			InsertatHead(val);
			return;
		}
		Node* last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		Node* newNode = new Node(val);
		last->next = newNode;
	}
	void InsertatMiddle(int index, int val)
	{
		if (index<0)
		{
			cout << "Index is Out of Bound." << endl;
			return;
		}
		if (index == 0)
		{
			InsertatHead(val);
			return;
		}
		int currIndex = 1;
		Node* currNode = head;
		while (currNode != NULL && currIndex < index)
		{
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode == NULL)
		{
			cout << "Index out of Bounds." << endl;
			return;
		}
		Node* newNode = new Node(val);
		newNode->next = currNode->next;
		currNode->next = newNode;
	}

	void deleteatHead()
	{
		Node* deletedNode = head;
		head = head->next;
		delete deletedNode;
	}

	void deletion(int val)
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty." << endl;
			return;
		}
		if (head->next == NULL)
		{
			deleteatHead();
			return;
		}
		Node* currNode = head;
		while (currNode->next!=NULL && currNode->next->data != val)
		{
			currNode = currNode->next;
		}
		if (currNode->next == NULL)
		{
			cout << val << " is not Found in the List.";
			return;
		}

		Node* deletedNode = currNode->next;
		currNode->next = currNode->next->next;
		delete deletedNode;
	}
	
	Node* gethead()
	{
		return head;
	}

	bool Search(int val)
	{
		Node* currNode = head;
		while (currNode->next != NULL)
		{
			if (currNode->data == val)
			{
				return true;
			}
			currNode = currNode->next;
		}

		return false;
	}

	void display()
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty." << endl;
			return;
		}
		Node* currNode = head;
		while (currNode != NULL)
		{
			cout << currNode->data << "->";
			currNode=currNode->next;
		}
		cout <<"NULL"<<endl;
	}

	void BubbleSort()
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty." << endl;
			return;
		}
		bool sorted;
		Node* end = NULL;
		do {
			sorted = true;
			Node* current = head;
			while (current->next != end)
			{
				if (current->data > current->next->data)
				{
					int temp = current->data;
					current->data = current->next->data;
					current->next->data = temp;
					sorted = false;
				}
				current = current->next;
			}
			end = current;
		} while (!sorted);
	}
	
	void Removeduplicate()
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}

		Node* current = head;
		while (current!=NULL && current->next != NULL)
		{
			if (current->data == current->next->data)
			{
				Node* duplicate = current->next;
				current->next = current->next->next;
				delete duplicate;
			}
			else
			{
				current = current->next;
			}
		}
	}
};

Node* mergeSortedLists(Node* l1, Node* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}

	Node* result = NULL;
	if (l1->data < l2->data)
	{
		result = l1;
		result->next = mergeSortedLists(l1->next, l2);
	}
	else
	{
		result = l2;
		result->next = mergeSortedLists(l1, l2->next);
	}

	return result;
}



int main()
{
	LinkedList ll;
	ll.InsertatTail(1);
	ll.InsertatTail(3);
	ll.InsertatTail(5);
	ll.InsertatHead(56);
	ll.InsertatHead(5);
	ll.display();
	cout << endl << ll.Search(56);
	cout << endl << ll.Search(17)<<endl;
	ll.InsertatMiddle(1, 6);
	ll.InsertatMiddle(5, 7);
	ll.InsertatMiddle(3, 7);
	ll.InsertatMiddle(2, 4);
	ll.display();
	ll.BubbleSort();
	ll.Removeduplicate();
	ll.display();

	LinkedList l2;
	l2.InsertatHead(11);
	l2.InsertatHead(13);
	l2.InsertatHead(15);
	l2.InsertatHead(12);
	l2.InsertatTail(10);
	l2.display();
	l2.BubbleSort();
	l2.display();

	LinkedList mergedlist;
	mergedlist.head = mergeSortedLists(ll.gethead(), l2.gethead());

	mergedlist.display();

	return 0;
}*/


/*class Node
{
public:
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

class LinkedList
{
private:
	Node* head = NULL;
public:
	void InsertatHead(int val)
	{
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}
	void InsertatTail(int val)
	{
		if (head == NULL)
		{
			InsertatHead(val);
			return;
		}
		Node* last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		Node* newNode = new Node(val);
		last->next = newNode;
	}

	void InsertatMiddle(int index, int val)
	{
		if (index < 0)
		{
			cout << "Index is out of Bound." << endl;
			return;
		}
		if (index == 0)
		{
			InsertatHead(val);
			return;
		}
		int currindex = 1;
		Node* current = head;
		while (current != NULL && currindex < index)
		{
			currindex++;
			current = current->next;
		}
		if (current == NULL)
		{
			cout << "Index is out of bound" << endl;
			return;
		}
		Node* newNode = new Node(val);
		newNode->next = current->next;
		current->next = newNode;
	}

	void deleteathead()
	{
		Node* deletedNode = head;
		head = head->next;
		delete deletedNode;
	}

	void deleteattail()
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty." << endl;
			return;
		}
		
		Node* last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		Node* deletedNode = last->next;
		last->next = last->next->next;
		delete deletedNode;
	}

	void deletion(int val)
	{
		if (head == NULL)
		{
			cout << "list is Empty." << endl;
			return;
		}
		if (head->next == NULL)
		{
			deleteathead();
			return;
		}
	}
};*/


/*class Node
{
public:
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node* head;
	LinkedList()
	{
		head = NULL;
	}

	void insertathead(int val)
	{
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}

	void insertattail(int val)
	{
		if (head == NULL)
		{
			insertathead(val);
			return;
		}
		Node* last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		Node* newNode = new Node(val);
		last->next = newNode;
	}

	void insertinmiddle(int val, int index)
	{
		if (index < 0)
		{
			cout << "Index is out of Bounds." << endl;
			return;
	    }
		if (index == 0)
		{
			insertathead(val);
			return;
		}
		
		Node* curr = head;
		int currIndex=1;
		while (curr != NULL && currIndex < index)
		{
			curr = curr->next;
			currIndex++;
		}
		
		if (curr == NULL)
		{
			cout << "Index is out of Bounds." << endl;
			return;
		}
		
		Node* newNode = new Node(val);
		newNode->next = curr->next;
		curr->next = newNode;
	}

	void deleteathead()
	{
		Node* deletedNode = head;
		head = head->next;
		delete deletedNode;
	}

	void deleteattail()
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty.";
			return;
		}

		if (head->next == NULL)
		{
			deleteathead();
			return;
		}

		Node* secondlast = head;
		while (secondlast->next->next != NULL)
		{
			secondlast = secondlast->next;
		}

		Node* deletedNode = secondlast->next;
		secondlast->next = NULL;
		delete deletedNode;
	}

	void deletion(int val)
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty." << endl;
			return;
		}

		if (head->data == val)
		{
			deleteathead();
			return;
		}

		Node* curr = head;
		Node* pre = NULL;

		while (curr != NULL && curr->data != val)
		{
			pre = curr;
			curr = curr->next;
		}

		pre->next = curr->next;
		delete curr;
	}

	void display()
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty." << endl;
			return;
		}
		Node* curr = head;
		cout << "Data : ";
		while (curr != NULL)
		{
			cout << curr->data << ", ";
			curr = curr->next;
		}
		cout << endl;
	}
};*/

/*class Node
{
public:
	int val;
	Node* next;

	Node(int v)
	{
		val = v;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node* head;

	LinkedList()
	{
		head = NULL;
	}
	void insertathead(int val)
	{
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}

	void insertattail(int val)
	{
		if (head == NULL)
		{
			insertathead(val);
			return;
		}
		
		Node* last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		
		Node* newNode = new Node(val);
		last->next = newNode;
	}

	void insertinmiddle(int val, int index)
	{
		if (index < 0)
		{
			cout << "Index Out of bounds." << endl;
			return;
		}
		if (index == 0)
		{
			insertathead(val);
			return;
		}
		Node* curr = head;
		int currindex = 1;
		while (curr != NULL && currindex < index)
		{
			curr = curr->next;
			currindex++;
		}
		if (curr == NULL)
		{
			cout << "Index Out of bounds." << endl;
			return;
		}

		Node* newNode = new Node(val);
		newNode->next = curr->next;
		curr->next = newNode;
	}

	void deleteathead()
	{
		Node* deletedNode = head;
		head = head->next;
		delete deletedNode;
	}

	void deleteattail()
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty." << endl;
			return;
		}

		if (head->next == NULL)
		{
			deleteathead();
			return;
		}

		Node* secondlast = head;
		while (secondlast->next->next != NULL)
		{
			secondlast = secondlast->next;
		}
		Node* deletedNode = secondlast->next;
		secondlast->next = NULL;
		delete deletedNode;
	}

	void deletion(int n)
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		if (head->val == n)
		{
			deleteathead();
		}
		Node* curr = head;
		Node* pre = NULL;
		while (curr != NULL && curr->val != n)
		{
			pre = curr;
			curr = curr->next;
		}

		pre->next = curr->next;
		delete curr;
	}

	void display()
	{
		if (head == NULL)
		{
			cout << "Linked List is Empty." << endl;
			return;
		}

		Node* curr = head;
		cout << "Data : ";
		while (curr != NULL)
		{
			cout <<" "<<curr->val << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};*/


class Node
{
public:
	int value;
	Node* next;

	Node(int v)
	{
		value = v;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node* head;

	LinkedList()
	{
		head = NULL;
	}

	void insertathead(int v)
	{
		Node* newNode = new Node(v);
		newNode->next = head;
		head = newNode;
	}

	void insertattail(int v)
	{
		if (head == NULL)
		{
			insertathead(v);
			return;
		}
		Node* last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		Node* newNode = new Node(v);
		last->next = newNode;
	}

	void insertinmiddle(int v, int index)
	{
		if (index < 0)
		{
			cout << "Index out of bounds." << endl;
			return;
		}
		if (index == 0)
		{
			insertathead(v);
			return;
		}

		Node* curr = head;
		int currindex=1;

		while (curr != NULL && currindex < index)
		{
			curr = curr->next;
			currindex++;
		}

		if (curr == NULL)
		{
			cout << "Index out of bounds." << endl;
			return;
		}

		Node* newNode = new Node(v);
		newNode->next = curr->next;
		curr->next = newNode;
	}

	void deleteathead()
	{
		Node* deletedNode = head;
		head = head->next;
		delete deletedNode;
	}

	void deleteattail()
	{
		if (head == NULL)
		{
			cout << "List is Empty." << endl;
			return;
		}

		if (head->next == NULL)
		{
			deleteathead();
			return;
		}

		Node* secondlast = head;
		while (secondlast->next->next != NULL)
		{
			secondlast = secondlast->next;
		}

		Node* deletedNode = secondlast->next;
		secondlast->next = NULL;
		delete deletedNode;
	}

	void deletion(int v)
	{
		if (head == NULL)
		{
			cout << "List is Empty." << endl;
			return;
		}
		if (v == head->value)
		{
			deleteathead();
			return;
		}
		Node* curr = head;
		Node* pre = NULL;

		while (curr != NULL && curr->value != v)
		{
			pre = curr;
			curr = curr->next;
		}

		if (curr == NULL)
		{
			cout << "value not found." << endl;
			return;
		}

		pre->next = curr->next;
		delete curr;
	}

	void display()
	{
		if (head == NULL)
		{
			cout << "List is Empty." << endl;
			return;
		}

		Node* curr = head;
		cout << "Data : ";
		while (curr != NULL)
		{
			cout << " " << curr->value << " ";
			curr = curr->next;
		}
	}
};

void main()
{
	LinkedList ll;
	int choice;

	do {
		cout << "1.Insert at head" << endl;
		cout << "2.Insert at tail" << endl;
		cout << "3.Insert by value" << endl;
		cout << "4.Delete at head" << endl;
		cout << "5.Delete at tail" << endl;
		cout << "6.Delete by Value" << endl;
		cout << "7.Display" << endl;
		cout << "8.Exit" << endl;
		cout << "Enter Your Choice : " << endl;
		cin >> choice;

		if (choice == 1)
		{
			int val;
			cout << "Enter Value : ";
			cin >> val;
			ll.insertathead(val);
		}
		else if (choice == 2)
		{
			int val;
			cout << "Enter Value : ";
			cin >> val;
			ll.insertattail(val);
		}
		else if (choice == 3)
		{
			int val,index;
			cout << "Enter Value : ";
			cin >> val;
			cout << "Enter Index to Enter Value : ";
			cin >> index;
			ll.insertinmiddle(val,index);
		}
		else if (choice == 4)
		{
			ll.deleteathead();
		}
		else if (choice == 5)
		{
			ll.deleteattail();
		}
		else if (choice == 6)
		{
			int val;
			cout << "Enter Value : ";
			cin >> val;
			ll.deletion(val);
		}
		else if (choice == 7)
		{
			ll.display();
		}
		else if (choice == 8)
		{
			cout << "Exiting." << endl;
		}
		else
		{
			cout << "Invalid Choice!" << endl;
		}
	} while (choice != 8);
}