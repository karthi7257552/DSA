#include <iostream>
using namespace std;
int main()
{
    int n, m;
    int i, j;
    int a[10][10], b[10][10], res[10][10];

    cout << "enter row and col:";
    cin >> n >> m;

    cout << "enter first matrix:";
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];

    cout << "enter second matrix:";
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> b[i][j];

    cout << "select: 1(Add) 2(Sub) 3(Product) 4(Transpose A) 5(Transpose B): ";
    int x;
    cin >> x;

    switch (x)
    {
    case 1:
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                res[i][j] = a[i][j] + b[i][j];
        break;

    case 2:
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                res[i][j] = a[i][j] - b[i][j];
        break;

    case 3:
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                res[i][j] = 0;
                for (int k = 0; k < m; k++)
                    res[i][j] += a[i][k] * b[k][j];
            }
        break;

    case 4:
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                cout << a[j][i] << " ";
            cout << "\n";
        }
    case 5:
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                cout << b[j][i] << " ";
            cout << "\n";
        }

    default:
        cout << "invalid choice!";
        return 0;
    }

    cout << "Result:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}