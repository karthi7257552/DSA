#include <iostream>
using namespace std;

// Structure for node
struct node
{
    int data;
    node *next;
    node *prev;
};

int main()
{
    node *head = NULL;
    int val;

    cout << "Enter value to insert: ";
    cin >> val;

    // Check if list is empty
    if (head == NULL)
    {
        node *newnode = new node();
        newnode->data = val;
        newnode->next = NULL;
        newnode->prev = NULL;

        head = newnode;

        cout << "Node inserted successfully into empty list.\n";
    }

    // Display list
    if (head != NULL)
    {
        cout << "List: ";
        cout << head->data << " -> NULL\n";
    }

    return 0;
}