#include <iostream>
using namespace std;

// Structure for node
struct node
{
    int data;
    node *next;
    node *prev;
};

// Insert at end
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

// Delete by value
node *deleteValue(node *head, int key)
{
    node *temp = head;

    // Search for node
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Element not found\n";
        return head;
    }

    // If first node
    if (temp->prev == NULL)
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    delete temp;
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
    int n, val, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> val;
        head = insertEnd(head, val);
    }

    display(head);

    cout << "Enter value to delete: ";
    cin >> key;

    head = deleteValue(head, key);

    display(head);

    return 0;
}