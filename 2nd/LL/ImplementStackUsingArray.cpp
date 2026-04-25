#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

// push element
void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack is full\n";
    } else {
        top = top + 1;
        stack[top] = val;
        cout << "Inserted: " << val << endl;
    }
}

// pop element
void pop() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Deleted: " << stack[top] << endl;
        top = top - 1;
    }
}

// check empty
void checkEmpty() {
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";
}

// check full
void checkFull() {
    if (top == MAX - 1)
        cout << "Stack is full\n";
    else
        cout << "Stack is not full\n";
}

// display stack
void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int ch, val;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1.Push\n2.Pop\n3.Check Empty\n4.Check Full\n5.Display\n6.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                checkEmpty();
                break;

            case 4:
                checkFull();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exit\n";
                break;

            default:
                cout << "Wrong choice\n";
        }

    } while (ch != 6);

    return 0;
}