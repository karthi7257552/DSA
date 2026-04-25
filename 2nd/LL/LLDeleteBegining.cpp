#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

// create list
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

// delete beginning
node *deleteBeg(node *head)
{
    if (head == NULL)
    {
        cout << "List empty\n";
        return head;
    }

    node *temp = head;
    head = head->next;
    delete temp;

    return head;
}

// display
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
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        head = insertEnd(head, val);
    }

    head = deleteBeg(head);

    display(head);
}