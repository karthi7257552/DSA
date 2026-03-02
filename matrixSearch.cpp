#include <iostream>
using namespace std;

int main()
{
    int a[10][10], rows, cols, key;
    bool found = false;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter element to search: ";
    cin >> key;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(a[i][j] == key)
            {
                cout << "Element found at position: (" << i << "," << j << ")";
                found = true;
                break;
            }
        }
        if(found)
            break;
    }

    if(!found)
        cout << "Element not found";

    return 0;
}