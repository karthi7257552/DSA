#include <iostream>
using namespace std;
int main()
{

    int a[10], pos = -1, val, i, n;
    cout << "enter the n:";
    cin >> n;

    cout << "enter elements:";
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "array:";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "enter the elemet to delete\n";
    cin >> val;

    for (i = 0; i < n; i++)
    {
        if (a[i] == val)
        {
            pos = i;
            break;
        }
    }
    cout << "val:" << val << "at position" << pos;

    if (pos == -1)
    {
        cout << "element not found!";
    }
    else
    {
        for (i = pos; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    }
    cout << "array:";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}