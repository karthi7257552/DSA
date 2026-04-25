#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function to insert a node at the beginning
void insertAtBeginning(Node **head_ref, int new_data)
{
    Node *new_node = new Node();

    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    int new_data;

    cout << "Enter elements of the linked list (enter -1 to stop):" << endl;

    do
    {
        cin >> new_data;

        if (new_data != -1)
        {
            insertAtBeginning(&head, new_data);
        }

    } while (new_data != -1);

    cout << "Original linked list: ";
    printList(head);

    cout << "\nEnter data to insert at the beginning: ";
    cin >> new_data;

    insertAtBeginning(&head, new_data);

    cout << "Updated linked list: ";
    printList(head);

    return 0;
}