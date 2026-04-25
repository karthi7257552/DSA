#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Function to insert at end (to create list)
void insertEnd(int value)
{
    Node *newNode, *temp;

    newNode = new Node();
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Function to delete all nodes
void deleteAll()
{
    if (head == NULL)
    {
        cout << "List is already empty";
        return;
    }

    Node *temp = head;
    Node *nextNode;

    // Break circular link first
    Node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    last->next = NULL; // convert to linear list

    // Delete nodes one by one
    while (temp != NULL)
    {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = NULL;
    cout << "All nodes deleted successfully";
}

// Function to display list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node *temp = head;

    cout << "Circular Linked List: ";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)";
}

// Main function
int main()
{
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;
        insertEnd(value);
    }

    display();

    cout << "\nDeleting all nodes...\n";
    deleteAll();

    display();

    return 0;
}