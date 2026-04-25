#include <iostream>
using namespace std;

// Structure for node
struct node
{
    int data;
    node *next;
    node *prev;
};

// Insert at end (to create list)
node* insertEnd(node *head, int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
        return newnode;

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

// Display list
void display(node *head)
{
    node *temp = head;
    cout << "\nList: ";
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Delete node at beginning
node* deleteBeginning(node *head)
{
    // If list is empty
    if (head == NULL)
    {
        cout << "List is empty\n";
        return head;
    }

    node *temp = head;

    // Move head to next node
    head = head->next;

    // If list is not empty after deletion
    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp; // delete old first node

    return head;
}

int main()
{
    node *head = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Create list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> val;
        head = insertEnd(head, val);
    }

    display(head);

    // Delete first node
    head = deleteBeginning(head);

    cout << "\nAfter deleting first node:";
    display(head);

    return 0;
}