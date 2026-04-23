#include <iostream>
using namespace std;

#define MAX 5

int queueArr[MAX];
int front = -1;
int rear = -1;

// insert (enqueue)
void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        cout << "Queue is full\n";
    }
    else
    {
        if (front == -1) // first element
            front = 0;
        rear = rear + 1;
        queueArr[rear] = val;
        cout << "Inserted: " << val << endl;
    }
}

// delete (dequeue)
void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Deleted: " << queueArr[front] << endl;
        front = front + 1;
    }
}

// display
void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queueArr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int ch, val;

    do
    {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            enqueue(val);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Exit\n";
            break;

        default:
            cout << "Wrong choice\n";
        }

    } while (ch != 4);

    return 0;
}