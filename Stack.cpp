#include<iostream>
using namespace std;

const int size = 10;
class Stack
{
private:
	int arr[::size];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	void push(int x)
	{
		if (!isFull())
		{
			arr[++top] = x;
		}
		else
		{
			cout << "Stack is Full, Cannot Push " << x << endl;
		}
	}
	int pop()
	{
		if (!isEmpty())
		{
			int data = arr[top];
			top--;
			return data;
		}
		else
		{
			cout << "Stack is Empty, Cannot Pop" << endl;
		}
	}
	
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
			return false;
	}
	
	bool isFull()
	{
		if (top == ::size-1)
		{
			return true;
		}
		else
			return false;
	}

	int size()
	{
		return ::size;
	}

	void display()
	{
		for (int i = top; i >= 0; i--)
		{
			cout << arr[i] << endl;
		}
	}
};

int main()
{
	Stack st;
	st.push(5);
	st.push(6);
	st.push(7);
	st.push(8);
	st.push(9);
	st.push(10);
	cout << st.size() << endl;
	st.display();


}

/*class Stack {
public:
	Stack(int stack_size);
	~Stack();
	void push(char x); 
	char pop();
	bool isEmpty(); 
	bool isFull();
private:
	char* contents;
	int top;
	int maxSize;
};
Stack::Stack(int stack_size)
{
	contents = new char[stack_size]; 
	if (contents == NULL) {
		cout << "Insufficient memory to initialize stack.\n";
		exit(1);
	}
	maxSize = stack_size;
	top = -1;
}
Stack::~Stack()
{
	delete[] contents;
	contents = NULL;
	maxSize = 0;
	top = -1;
}
bool Stack::isEmpty() 
{
	return top < 0;
}
void Stack::push(char element)
{
		if (isFull()) {
			cout << "Can't push element on stack: stack is full.\n"; 
			exit(1);
		}
	contents[++top] = element;
}
char Stack::pop()
{
	if (!isEmpty())
	{
	   return contents[top--];
	}
	else
		cout << "Stack is empty, cannot pop" << endl;
	return -1;
}

bool Stack::isFull()
{
	if (top == maxSize - 1)
	{
		return true;
	}
	else
		return false;
}

int main()
{
	Stack st(6);
	st.push('a');
	st.push('b');
	st.push('c');
	st.push('d');
	st.push('e');
	st.push('f');
	
	for (int i = 0; i < 6; i++)
	{
		cout<<st.pop() << endl;
	}
}*/
