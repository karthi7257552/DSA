#include <iostream>
using namespace std;

// Structure for node
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Function to create circular linked list
void createList(int n) {
    Node *newNode, *temp;
    int value;

    if (n <= 0) {
        cout << "List size should be greater than 0";
        return;
    }

    // Create first node
    cout << "Enter data for node 1: ";
    cin >> value;

    head = new Node();
    head->data = value;
    head->next = head;  // circular link

    temp = head;

    // Create remaining nodes
    for (int i = 2; i <= n; i++) {
        cout << "Enter data for node " << i << ": ";
        cin >> value;

        newNode = new Node();
        newNode->data = value;
        newNode->next = head;  // point to first node

        temp->next = newNode;
        temp = newNode;
    }
}

// Function to display list
void displayList() {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    cout << "\nCircular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)";
}

// Main function
int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    createList(n);
    displayList();

    return 0;
}