#include<iostream>
using namespace std;

int binarySearch(int roll[], int n, int item)
{
    int low = 0, high = n-1, mid;

    while(low <= high)
    {
        mid = (low + high)/2;

        if(roll[mid] == item)
            return mid;
        else if(roll[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n,i;
    int roll[50];
    string name[50];

    cout<<"Enter number of Msc CS students: ";
    cin>>n;

    cout<<"Enter Roll No and Name:\n";
    for(i=0;i<n;i++)
    {
        cin>>roll[i]>>name[i];
    }

    int item;
    cout<<"Enter roll number to search: ";
    cin>>item;

    int index = binarySearch(roll,n,item);

    if(index != -1)
        cout<<"Student Found: "<<name[index];
    else
        cout<<"Student Not Found";

    return 0;
}