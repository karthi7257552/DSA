#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int n = s.length();
    bool Pal = true;

    for(int i = 0; i < n / 2; i++) {
        if(s[i] != s[n - 1 - i]) {
            Pal = false;
            break;
        }
    }

    if(Pal)
        cout << "It is a palindrome";
    else
        cout << "It is not a palindrome";

    return 0;
}