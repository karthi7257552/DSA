#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Function to insert at beginning
void insertBegin(int value)
{
    Node *newNode, *temp;

    newNode = new Node();
    newNode->data = value;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    // Find last node
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    // Insert at beginning
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
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
        insertBegin(value);
    }

    display();

    return 0;
}