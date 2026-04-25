#include <iostream>
#include <string>

using namespace std;

// Node structure
struct Student
{
    string name;
    int rollNo;
    Student *next;
};

// Function to insert a new student in sorted order based on rollNo
void insert(Student *&head, string name, int rollNo)
{
    Student *newNode = new Student();
    if (newNode == nullptr)
    {
        cout << "Memory allocation failed\n";
        exit(EXIT_FAILURE);
    }

    newNode->name = name;
    newNode->rollNo = rollNo;
    newNode->next = nullptr;

    // If list is empty or the new roll number is smaller than the head's roll number
    if (head == nullptr || rollNo < head->rollNo)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Student *current = head;
        // Traverse to find the correct position
        while (current->next != nullptr && current->next->rollNo <= rollNo)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the linked list
void printList(Student *head)
{
    Student *current = head;
    cout << "Student List:\n";
    while (current != nullptr)
    {
        cout << "Roll No: " << current->rollNo << " Name: " << current->name << "\n";
        current = current->next;
    }
}

int main()
{
    Student *head = nullptr;
    int num_students;
    string name;
    int rollNo;

    cout << "Enter the number of students: ";
    cin >> num_students;

    // Clear the newline character left in the input buffer by cin
    cin.ignore();

    cout << "Enter " << num_students << " students (name and roll no):\n";
    for (int i = 0; i < num_students; ++i)
    {
        cout << "Student " << i + 1 << ":\n";

        cout << "Name: ";
        getline(cin, name);

        cout << "Roll No: ";
        cin >> rollNo;

        // Clear the newline character for the next iteration's getline
        cin.ignore();

        insert(head, name, rollNo);
    }

    printList(head);

    // Free dynamically allocated memory (C++ best practice)
    Student *current = head;
    while (current != nullptr)
    {
        Student *nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}