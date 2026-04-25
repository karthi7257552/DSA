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

// Recursive function to print in reverse
void reversePrint(Node *temp)
{
    static bool firstCall = true;

    if (temp->next == head && !firstCall)
    {
        cout << temp->data << " ";
        return;
    }

    firstCall = false;
    reversePrint(temp->next);
    cout << temp->data << " ";
}

// Main function
int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    createList(n);

    if (head == NULL)
    {
        cout << "List is empty";
        return 0;
    }

    cout << "\nElements in reverse order: ";
    reversePrint(head);

    return 0;
}