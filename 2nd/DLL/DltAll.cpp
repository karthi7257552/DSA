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

// Delete all nodes
node* deleteAll(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        node *nextNode = temp->next; // store next node
        delete temp;                 // free memory
        temp = nextNode;             // move forward
    }

    head = NULL; // list becomes empty
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

    // Delete all nodes
    head = deleteAll(head);

    cout << "\nAll nodes deleted successfully.\n";
    display(head);

    return 0;
}