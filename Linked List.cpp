#include<iostream>
using namespace std;

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
