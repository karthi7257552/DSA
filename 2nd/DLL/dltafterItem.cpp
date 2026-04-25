#include <iostream>
using namespace std;

// Structure
struct node
{
    int data;
    node *next;
    node *prev;
};

// Insert at end
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

// Delete node after specific item
node* deleteAfter(node *head, int item)
{
    node *temp = head;

    // Search for item
    while (temp != NULL && temp->data != item)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Deletion not possible\n";
        return head;
    }

    node *delNode = temp->next;

    temp->next = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = temp;

    delete delNode;

    return head;
}

// Display
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

    cout << "Enter item after which to delete: ";
    cin >> item;

    head = deleteAfter(head, item);

    display(head);

    return 0;
}
