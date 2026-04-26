#include <iostream>
using namespace std;

int main()
{
    int degree;

    cout << "Enter degree of polynomial: ";
    cin >> degree;

    int coeff[degree + 1];

    // Input coefficients
    cout << "Enter coefficients:\n";
    for (int i = degree; i >= 0; i--)
    {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coeff[i];
    }

    // Display polynomial
    cout << "\nPolynomial: ";
    for (int i = degree; i >= 0; i--)
    {
        if (coeff[i] != 0)
        {
            cout << coeff[i] << "x^" << i;
            if (i != 0)
                cout << " + ";
        }
    }

    return 0;
}