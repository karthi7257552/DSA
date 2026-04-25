#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Function to insert at end (for creating list)
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

// Function to delete at position
void deleteAtPosition(int pos)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node *temp = head, *prev = NULL;

    // Case 1: delete first node
    if (pos == 1)
    {
        // Only one node
        if (head->next == head)
        {
            delete head;
            head = NULL;
            cout << "Node deleted";
            return;
        }

        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;
        delete temp;

        cout << "Node deleted at position 1";
        return;
    }

    // Case 2: delete at other positions
    for (int i = 1; i < pos && temp->next != head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // Check if position is valid
    if (temp == head)
    {
        cout << "Invalid position";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Node deleted at position " << pos;
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
    int n, value, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;
        insertEnd(value);
    }

    display();

    cout << "\nEnter position to delete: ";
    cin >> pos;

    deleteAtPosition(pos);

    display();

    return 0;
}