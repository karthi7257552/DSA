#include <iostream>
using namespace std;

int main()
{
    int n, item;
    cout << "Enter size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> item;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            cout << "Element found at index " << i;
            return 0;
        }
    }

    cout << "Element not found";
    return 0;
}
