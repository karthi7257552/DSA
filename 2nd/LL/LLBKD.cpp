#include <iostream>
using namespace std;

// Structure for a node
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Function to create a new node
Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at end
Node *insertEnd(Node *head, int value)
{
    Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Traverse forward
void traverseForward(Node *head)
{
    Node *temp = head;
    cout << "\nForward Traversal: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Traverse backward
void traverseBackward(Node *head)
{
    Node *temp = head;

    // Move to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    cout << "\nBackward Traversal: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

int main()
{
    Node *head = NULL;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        head = insertEnd(head, value);
    }

    traverseForward(head);
    traverseBackward(head);

    return 0;
}