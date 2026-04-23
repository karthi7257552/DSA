#include <iostream>
using namespace std;

// node structure
struct node
{
    int data;
    struct node *next;
};

// insert at end (for creating list)
struct node *insertEnd(struct node *head, int val)
{
    struct node *newnode = new node();
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    return head;
}

// insert at position (middle)
struct node *insertPos(struct node *head, int val, int pos)
{
    struct node *newnode = new node();
    newnode->data = val;

    // insert at beginning
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }

    struct node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position\n";
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

// display
void display(struct node *head)
{
    struct node *temp = head;

    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    cout << "Linked list: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    struct node *head = NULL;
    int n, val, pos;

    // create list
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> val;
        head = insertEnd(head, val);
    }

    cout << "Original List:\n";
    display(head);

    // insert in middle
    cout << "Enter value to insert: ";
    cin >> val;
    cout << "Enter position: ";
    cin >> pos;

    head = insertPos(head, val, pos);

    cout << "After insertion:\n";
    display(head);

    return 0;
}