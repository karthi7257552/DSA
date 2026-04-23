#include <iostream>
using namespace std;
int main()
{

    int n, i;
    cout << "enter no of students:";
    cin >> n;

    int roll[50];
    string name[50];

    for (i = 0; i < n; i++)
    {
        cout << "enter rollno  of student " << i + 1;
        cin >> roll[i];

        cout << "enter name of student " << i + 1;
        cin >> name[i];
    }

    for (i = 0; i < n; i++)
    {
        cout << i + 1 << ", name: " << name[i] << " " << "roll no: " << roll[i] << endl;
    }
}