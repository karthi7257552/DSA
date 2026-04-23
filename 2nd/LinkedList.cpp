#include <iostream>
using namespace std;

// node structure
struct node {
    int data;
    struct node* next;
};

int main() {
    int n, val;
    
    cout << "Enter number of nodes: ";
    cin >> n;

    struct node *head = NULL, *temp, *newnode;

    // create linked list
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;

        newnode = new node();
        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // display linked list
    cout << "Linked list elements: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}