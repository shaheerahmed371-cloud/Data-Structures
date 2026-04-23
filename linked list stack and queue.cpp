#include <iostream>
#include <string>

using namespace std;

// Structure to represent a book
struct Book {
    string title;
    string author;
    float price;
    Book* next; // Pointer to the next book in the stack
};

// Stack class implemented using a linked list
class Stack {
private:
    Book* top; // Pointer to the top of the stack

public:
    Stack() : top(nullptr) {} // Constructor to initialize an empty stack

    // Function to push a book onto the stack
    void push(string title, string author, float price) {
        Book* newBook = new Book();
        newBook->title = title;
        newBook->author = author;
        newBook->price = price;
        newBook->next = top;
        top = newBook;
        cout << "Book added to stack: " << title << endl;
    }

    // Function to pop a book from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to pop." << endl;
            return;
        }
        Book* temp = top;
        top = top->next;
        cout << "Book removed from stack: " << temp->title << endl;
        delete temp;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to find and delete a book from the stack
    void findAndDelete(string title) {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot find or delete book." << endl;
            return;
        }

        Book* current = top;
        Book* previous = nullptr;

        while (current != nullptr) {
            if (current->title == title) {
                // Book found
                if (previous == nullptr) {
                    // The book is at the top of the stack
                    top = current->next;
                }
                else {
                    // The book is in the middle or bottom
                    previous->next = current->next;
                }
                cout << "Book deleted from stack: " << current->title << endl;
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }

        cout << "Book not found in stack." << endl;
    }

    // Function to display all books in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Book* current = top;
        cout << "Books in stack:" << endl;
        while (current != nullptr) {
            cout << "Title: " << current->title
                << ", Author: " << current->author
                << ", Price: " << current->price << endl;
            current = current->next;
        }
    }

    // Destructor to clean up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    int choice;
    string title, author;
    float price;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add book to stack" << endl;
        cout << "2. Remove book from stack" << endl;
        cout << "3. Find and delete book from stack" << endl;
        cout << "4. Display all books in stack" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            cout << "Enter book price: ";
            cin >> price;
            stack.push(title, author, price);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            cout << "Enter title of book to delete: ";
            cin.ignore();
            getline(cin, title);
            stack.findAndDelete(title);
            break;

        case 4:
            stack.display();
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

/*#include <iostream>
#include <string>

using namespace std;

// Structure to represent an order
struct Order {
    int orderID;
    string customerName;
    string address;
    int numberOfItems;
    float payment;
    Order* next; // Pointer to the next order in the queue
};

// Queue class to manage orders
class OrderQueue {
private:
    Order* front; // Pointer to the front of the queue
    Order* rear;  // Pointer to the rear of the queue
    int nextOrderID; // Auto-incremented order ID

public:
    // Constructor to initialize an empty queue
    OrderQueue() : front(nullptr), rear(nullptr), nextOrderID(1) {}

    // Function to add a new order to the queue
    void addOrder(string customerName, string address, int numberOfItems, float payment) {
        Order* newOrder = new Order();
        newOrder->orderID = nextOrderID++;
        newOrder->customerName = customerName;
        newOrder->address = address;
        newOrder->numberOfItems = numberOfItems;
        newOrder->payment = payment;
        newOrder->next = nullptr;

        if (rear == nullptr) {
            // Queue is empty
            front = rear = newOrder;
        }
        else {
            // Add the new order at the rear of the queue
            rear->next = newOrder;
            rear = newOrder;
        }
        cout << "Order added with Order ID: " << newOrder->orderID << endl;
    }

    // Function to process the next order (FIFO)
    void processOrder() {
        if (isEmpty()) {
            cout << "No orders to process." << endl;
            return;
        }

        Order* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr; // Queue becomes empty
        }

        cout << "Processing Order ID: " << temp->orderID << endl;
        cout << "Customer Name: " << temp->customerName << endl;
        cout << "Address: " << temp->address << endl;
        cout << "Number of Items: " << temp->numberOfItems << endl;
        cout << "Payment: " << temp->payment << endl;

        delete temp;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to display all orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue." << endl;
            return;
        }

        Order* current = front;
        cout << "Orders in queue:" << endl;
        while (current != nullptr) {
            cout << "Order ID: " << current->orderID << ", Customer Name: " << current->customerName
                << ", Address: " << current->address << ", Number of Items: " << current->numberOfItems
                << ", Payment: " << current->payment << endl;
            current = current->next;
        }
    }

    // Destructor to clean up memory
    ~OrderQueue() {
        while (!isEmpty()) {
            processOrder();
        }
    }
};

int main() {
    OrderQueue queue;
    int choice;
    string customerName, address;
    int numberOfItems;
    float payment;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Order" << endl;
        cout << "2. Process Order" << endl;
        cout << "3. Display All Orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, customerName);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Number of Items: ";
            cin >> numberOfItems;
            cout << "Enter Payment: ";
            cin >> payment;
            queue.addOrder(customerName, address, numberOfItems, payment);
            break;

        case 2:
            queue.processOrder();
            break;

        case 3:
            queue.displayOrders();
            break;

        case 4:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}*/
