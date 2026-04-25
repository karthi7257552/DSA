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
        newnode->prev = temp;
    }

    return head;
}

// Display in reverse order
void displayReverse(node *head)
{
    node *temp = head;

    // Move to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    cout << "\nElements in Reverse Order: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
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

    // Reverse display
    displayReverse(head);

    return 0;
}