#include <iostream>
using namespace std;
int main()
{
    int n, m;
    int i, j;
    cout << "enter row and column:";
    cin >> n >> m;

    int a[50][50];

    cout << "enter values:";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Matrix";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}