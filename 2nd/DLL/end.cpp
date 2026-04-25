#include <iostream>
using namespace std;

// Structure for node
struct node
{
    int data;
    node *next;
    node *prev;
};

// Insert node at end
node *insertEnd(node *head, int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    // If list is empty
    if (head == NULL)
    {
        return newnode; // directly return new node
    }

    node *temp = head;

    // Traverse to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Link new node
    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

// Display list
void display(node *head)
{
    if (head == NULL)
    {
        cout << "\nList is empty\n";
        return;
    }

    node *temp = head;
    cout << "\nList: ";
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> val;
        head = insertEnd(head, val);
    }

    display(head);

    return 0;
}