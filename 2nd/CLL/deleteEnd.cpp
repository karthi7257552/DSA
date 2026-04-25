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

// Function to delete node at end
void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    // Case: only one node
    if (head->next == head)
    {
        delete head;
        head = NULL;
        cout << "Node deleted";
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    // Traverse to last node
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    // Remove last node
    prev->next = head;
    delete temp;

    cout << "Node deleted from end";
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

    cout << "\nDeleting node from end...\n";
    deleteEnd();

    display();

    return 0;
}