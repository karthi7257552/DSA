#include <iostream>
using namespace std;

// node structure
struct node {
    int data;
    node* prev;
    node* next;
};

// insert at end
node* insertEnd(node* head, int val) {
    node* newnode = new node();
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }

    return head;
}

// backward traversal
void traverseBackward(node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* temp = head;

    // go to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // traverse backward
    cout << "Backward traversal: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

// display forward (optional)
void displayForward(node* head) {
    node* temp = head;
    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        head = insertEnd(head, val);
    }

    displayForward(head);
    traverseBackward(head);

    return 0;
}