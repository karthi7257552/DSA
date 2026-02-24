#include <iostream>
using namespace std;

int binarySearch(int roll[], int n, int item)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (roll[mid] == item)
            return mid;
        else if (roll[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int roll[n];
    string name[n];

    cout << "Enter student details:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter student rollno:\n";
        cin >> roll[i];
        cout << "Enter student names:\n";
        cin >> name[i];
    }

    int item;
    cout << "Enter roll number to search: ";
    cin >> item;

    int index = binarySearch(roll, n, item);

    if (index != -1)
        cout << "Student Found: " << name[index];
    else
        cout << "Student Not Found";

    return 0;
}