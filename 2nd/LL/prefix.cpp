#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string exp;
    cout << "Enter prefix expression: ";
    cin >> exp;

    stack<int> s;

    // scan from right to left
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char ch = exp[i];

        // if operand
        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }
        else
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();

            int res;

            if (ch == '+')
                res = val1 + val2;
            else if (ch == '-')
                res = val1 - val2;
            else if (ch == '*')
                res = val1 * val2;
            else if (ch == '/')
                res = val1 / val2;

            s.push(res);
        }
    }

    cout << "Result = " << s.top();

    return 0;
}