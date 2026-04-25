#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *insertEnd(node *head, int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    return head;
}

// delete at position
node *deletePos(node *head, int pos)
{
    if (head == NULL)
    {
        cout << "List empty\n";
        return head;
    }

    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node *temp = head;

    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Invalid position\n";
        return head;
    }

    node *del = temp->next;
    temp->next = del->next;
    delete del;

    return head;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    node *head = NULL;
    int n, val, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        head = insertEnd(head, val);
    }

    cout << "Enter position to delete: ";
    cin >> pos;

    head = deletePos(head, pos);

    display(head);
}