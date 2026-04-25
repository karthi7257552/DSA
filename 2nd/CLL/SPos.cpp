#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Function to insert at position
void insertAtPosition(int value, int pos)
{
    Node *newNode, *temp;
    int i;

    newNode = new Node();
    newNode->data = value;

    // Case 1: Insert at beginning
    if (pos == 1)
    {
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

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return;
    }

    // Case 2: Insert at other positions
    temp = head;
    for (i = 1; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    // Insert node
    newNode->next = temp->next;
    temp->next = newNode;
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

    // Create list using end insertion
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;

        // simple insert at end logic
        Node *newNode = new Node();
        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    cout << "Enter value to insert: ";
    cin >> value;

    cout << "Enter position: ";
    cin >> pos;

    insertAtPosition(value, pos);

    display();

    return 0;
}