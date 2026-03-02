#include <iostream>
using namespace std;

int binarySearch(int a[], int low, int high, int item) {
    if (low > high)
        return -1; 

    int mid = (low + high) / 2;

    if (a[mid] == item)
        return mid;
    else if (a[mid] < item)
        return binarySearch(a, mid + 1, high, item);
    else
        return binarySearch(a, low, mid - 1, item);
}

int main() {
    int a[50];
    int n, item, i;

    cout << "Enter the size: ";
    cin >> n;

    cout << "Enter sorted elements: ";
    for(i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> item;

    int result = binarySearch(a, 0, n - 1, item);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}