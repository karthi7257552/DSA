#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int i, j;
    int a[50][50];

    bool found = false;
    int item;

    cout << "enter row and col:";
    cin >> n >> m;

    cout << "enter elemtns of matrix:";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "matrix\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "enter element to search:";
    cin >> item;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == item)
            {
                found = true;
                cout << item << " found at position " << a[i][j];
                break;
            }
            else
            {
                cout << "not found:"
            }
        }
    }

    return 0;
}