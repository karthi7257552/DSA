#include <iostream>
using namespace std;

int main()
{
    int a[50], n, val, pos = -1 ;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to delete: ";
    cin >> val;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        cout << "Element not found";
    }
    else
    {
 
        for (int i = pos; i < n - 1; i++)
            a[i] = a[i + 1];

        n--;

        cout << "Array after deletion:\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }

    return 0;
}