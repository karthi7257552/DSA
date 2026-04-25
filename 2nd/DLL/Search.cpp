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
node* insertEnd(node *head, int val)
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

// Display list
void display(node *head)
{
    node *temp = head;
    cout << "\nDoubly Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Search element
void search(node *head, int key)
{
    node *temp = head;
    int pos = 1;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Element found at position " << pos << endl;
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
    {
        cout << "Element not found\n";
    }
}

int main()
{
    node *head = NULL;
    int n, val, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Create list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> val;
        head = insertEnd(head, val);
    }

    // Display list
    display(head);

    // Search
    cout << "Enter element to search: ";
    cin >> key;

    search(head, key);

    return 0;
}