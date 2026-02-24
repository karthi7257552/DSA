#include<iostream>
using namespace std;

int main()
{
    int a[50], n, i, j, temp;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=1;i<n;i++)
    {
        temp = a[i];
        j = i-1;

        while(j>=0 && a[j] > temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }

    cout<<"Sorted array:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}