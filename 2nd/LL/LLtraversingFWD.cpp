#include <iostream>
using namespace std;

// node structure
struct node
{
    int data;
    node *next;
};

// create list (insert at end)
node *insertEnd(node *head, int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    return head;
}

// traversal (forward)
void traverse(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    node *temp = head;

    cout << "Elements: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
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

    cout << "Traversing list (forward):\n";
    traverse(head);

    return 0;
}