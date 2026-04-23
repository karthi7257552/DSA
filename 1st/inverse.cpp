#include <iostream>
using namespace std;

int main() {
    float a[2][2], det;

    cout << "Enter elements of 2x2 matrix:\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }

    // finding determinant
    det = a[0][0]*a[1][1] - a[0][1]*a[1][0];

    if(det == 0) {
        cout << "Inverse not possible (determinant is 0)";
    } else {
        cout << "Inverse of matrix is:\n";

        // formula for inverse of 2x2 matrix
        cout << a[1][1]/det << "  " << -a[0][1]/det << endl;
        cout << -a[1][0]/det << "  " << a[0][0]/det << endl;
    }

    return 0;
}