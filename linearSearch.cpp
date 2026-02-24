#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int i, j;
    int a[50][50];
    bool found = false;
    int item;

    cout << "Enter row  col: ";
    cin >> n >> m;

    cout << "Enter elements:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];

    cout << "Matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    cout << "Enter element to search: ";
    cin >> item;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == item)
            {
                cout << item << " found at position (" << i << "," << j << ")";
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
        cout << "Element not found";

    return 0;
}