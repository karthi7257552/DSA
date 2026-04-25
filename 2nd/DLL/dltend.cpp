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
node *insertEnd(node *head, int val)
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

// Delete node at end
node *deleteEnd(node *head)
{
    // If list is empty
    if (head == NULL)
    {
        cout << "List is empty\n";
        return head;
    }

    // If only one node
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    node *temp = head;

    // Traverse to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // temp is last node
    temp->prev->next = NULL;
    delete temp;

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

    // Delete last node
    head = deleteEnd(head);

    cout << "\nAfter deleting last node:";
    display(head);

    return 0;
}