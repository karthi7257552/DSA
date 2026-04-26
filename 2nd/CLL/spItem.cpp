#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at end
void insertEnd(int value)
{
    Node *newNode = new Node{value, NULL};

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete node after given item
void deleteAfter(int item)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;

    do
    {
        if (temp->data == item)
        {
            Node *delNode = temp->next;

            // Only one node
            if (delNode == temp)
            {
                delete delNode;
                head = NULL;
                cout << "Only node deleted\n";
                return;
            }

            temp->next = delNode->next;

            // If deleting head
            if (delNode == head)
                head = delNode->next;

            delete delNode;
            cout << "Node deleted after " << item << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Item not found\n";
}

// Display list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;
    cout << "Circular Linked List: ";

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

int main()
{
    int n, val, item;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> val;
        insertEnd(val);
    }

    display();

    cout << "Enter item after which to delete: ";
    cin >> item;

    deleteAfter(item);

    display();

    return 0;
}