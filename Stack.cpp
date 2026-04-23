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
    return 0;
}


