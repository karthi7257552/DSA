#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Create circular linked list
void createList(int n)
{
    Node *newNode, *temp;
    int value;

    if (n <= 0)
        return;

    cout << "Enter data for node 1: ";
    cin >> value;

    head = new Node();
    head->data = value;
    head->next = head;

    temp = head;

    for (int i = 2; i <= n; i++)
    {
        cout << "Enter data for node " << i << ": ";
        cin >> value;

        newNode = new Node();
        newNode->data = value;
        newNode->next = head;

        temp->next = newNode;
        temp = newNode;
    }
}

// Search function
void search(int key)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node *temp = head;
    int position = 1;
    bool found = false;

    do
    {
        if (temp->data == key)
        {
            cout << "Element found at position " << position;
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    if (!found)
    {
        cout << "Element not found";
    }
}

// Main function
int main()
{
    int n, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    createList(n);

    cout << "Enter value to search: ";
    cin >> key;

    search(key);

    return 0;
}