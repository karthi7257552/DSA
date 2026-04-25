#include <iostream>

using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Function to insert a node at a specific index
// Note: Using Node*& (reference to a pointer) instead of Node** for cleaner C++ syntax
void insertAtIndex(Node *&head_ref, int position, int new_data)
{
    if (position < 1)
    {
        cout << "Invalid position. Position should be >= 1.\n";
        return;
    }

    // Allocate memory using 'new' instead of malloc
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    Node *current = head_ref;

    // If inserting at the head
    if (position == 1)
    {
        new_node->next = head_ref;
        head_ref = new_node;
        return;
    }

    // Traverse to the node just before the insertion point
    for (int i = 1; i < position - 1 && current != nullptr; i++)
    {
        current = current->next;
    }

    // If position is greater than the number of nodes
    if (current == nullptr)
    {
        cout << "Position is out of bounds.\n";
        delete new_node; // Clean up memory to prevent leaks
        return;
    }

    // Insert the new node
    new_node->next = current->next;
    current->next = new_node;
}

// Function to print the linked list
void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;
    int new_data, position;

    cout << "Enter elements of the linked list (enter -1 to stop):\n";
    do
    {
        cin >> new_data;
        if (new_data != -1)
        {
            Node *new_node = new Node();
            new_node->data = new_data;
            new_node->next = head;
            head = new_node;
        }
    } while (new_data != -1);

    cout << "Original linked list: ";
    printList(head);

    cout << "\nEnter data to insert: ";
    cin >> new_data;

    cout << "Enter position to insert (1-based index): ";
    cin >> position;

    // No need to pass &head since we are using a reference to the pointer
    insertAtIndex(head, position, new_data);

    cout << "Updated linked list: ";
    printList(head);

    // Optional but recommended: write a loop here to 'delete' all nodes and free memory before exiting.

    return 0;
}