#include <iostream>
using namespace std;

int main()
{
    int m, n;
    float a[10][10];

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int rank = n;

    for (int i = 0; i < rank; i++)
    {

        if (a[i][i] != 0)
        {
            for (int j = 0; j < m; j++)
            {
                if (j != i)
                {
                    float ratio = a[j][i] / a[i][i];
                    for (int k = 0; k < rank; k++)
                    {
                        a[j][k] -= ratio * a[i][k];
                    }
                }
            }
        }
        else
        {
            bool reduce = true;

            for (int j = i + 1; j < m; j++)
            {
                if (a[j][i] != 0)
                {
                    for (int k = 0; k < rank; k++)
                    {
                        swap(a[i][k], a[j][k]);
                    }
                    reduce = false;
                    break;
                }
            }

            if (reduce)
            {
                rank--;

                for (int j = 0; j < m; j++)
                {
                    a[j][i] = a[j][rank];
                }
            }

            i--;
        }
    }

    cout << "Rank of the matrix = " << rank;

    return 0;
}