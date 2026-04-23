#include <iostream>
using namespace std;

// node structure
struct node
{
    int data;
    struct node *next;
};

// insert at end (to create list normally)
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

// insert at beginning
struct node *insertBeg(struct node *head, int val)
{
    struct node *newnode = new node();
    newnode->data = val;

    newnode->next = head;
    head = newnode;

    return head;
}

// display list
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
    int n, val;

    // Step 1: create list
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

    // Step 2: insert at beginning
    cout << "Enter value to insert at beginning: ";
    cin >> val;

    head = insertBeg(head, val);

    // Step 3: display updated list
    cout << "After inserting at beginning:\n";
    display(head);

    return 0;
}