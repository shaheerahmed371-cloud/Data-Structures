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
