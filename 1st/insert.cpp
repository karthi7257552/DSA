#include <iostream>
using namespace std;

int main()
{
    int a[50], n, pos, val;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter position: ";
    cin >> pos;

    cout << "Enter value: ";
    cin >> val;

    for (int i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = val;
    n++;

    cout << "arry::\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}