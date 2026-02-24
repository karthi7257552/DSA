#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int item) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == item)
            return mid;
        else if (a[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
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

    int result = binarySearch(a, n, item);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}