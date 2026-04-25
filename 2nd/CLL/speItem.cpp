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

// Function to insert after a specific item
void insertAfter(int item, int value)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node *temp = head;
    bool found = false;

    do
    {
        if (temp->data == item)
        {
            Node *newNode = new Node();
            newNode->data = value;

            newNode->next = temp->next;
            temp->next = newNode;

            cout << "Node inserted after " << item;
            found = true;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (!found)
    {
        cout << "Item not found in list";
    }
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

    cout << "\nCircular Linked List: ";
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
    int n, value, item;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;
        insertEnd(value);
    }

    cout << "Enter item after which to insert: ";
    cin >> item;

    cout << "Enter value to insert: ";
    cin >> value;

    insertAfter(item, value);

    display();

    return 0;
}