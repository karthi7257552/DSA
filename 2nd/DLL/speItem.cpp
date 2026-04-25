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

// Insert after specific item
node* insertAfter(node *head, int item, int val)
{
    node *temp = head;

    // Search for the item
    while (temp != NULL && temp->data != item)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Item not found\n";
        return head;
    }

    node *newnode = new node();
    newnode->data = val;

    // Linking
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }

    temp->next = newnode;

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

int main()
{
    node *head = NULL;
    int n, val, item;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> val;
        head = insertEnd(head, val);
    }

    display(head);

    cout << "Enter item after which to insert: ";
    cin >> item;

    cout << "Enter new value: ";
    cin >> val;

    head = insertAfter(head, item, val);

    display(head);

    return 0;
}