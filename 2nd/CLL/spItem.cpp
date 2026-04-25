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
    Node *newNode = new Node(), *temp;
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;
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
        cout << "List is empty";
        return;
    }

    Node *temp = head;

    do
    {
        if (temp->data == item)
        {
            Node *delNode = temp->next;

            // only one node
            if (delNode == temp)
            {
                delete delNode;
                head = NULL;
                cout << "Node deleted";
                return;
            }

            temp->next = delNode->next;

            // if deleting head
            if (delNode == head)
                head = delNode->next;

            delete delNode;
            cout << "Node deleted after " << item;
            return;
        }

        temp = temp->next;
    } while (temp != head);

    cout << "Item not found";
}

// Display
void display()
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node *temp = head;
    cout << "List: ";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)";
}

int main()
{
    int n, val, item;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        insertEnd(val);
    }

    display();

    cout << "\nEnter item after which to delete: ";
    cin >> item;

    deleteAfter(item);
    display();

    return 0;
}