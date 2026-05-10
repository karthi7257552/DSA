#include <iostream>
#include <stack>
#include <cmath> // for pow()
using namespace std;

int main()
{
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    stack<int> s;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // If operand (digit)
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
            // Check if enough operands exist
            if (s.size() < 2)
            {
                cout << "Invalid expression\n";
                return 0;
            }

            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();

            int res;

            switch (ch)
            {
            case '+':
                res = val1 + val2;
                break;
            case '-':
                res = val1 - val2;
                break;
            case '*':
                res = val1 * val2;
                break;
            case '/':
                res = val1 / val2;
                break;
            case '^':
                res = pow(val1, val2);
                break;
            default:
                cout << "Invalid operator\n";
                return 0;
            }

            s.push(res);
        }
    }

    // Final check
    if (s.size() != 1)
    {
        cout << "Invalid expression\n";
        return 0;
    }

    cout << "Result = " << s.top();
    return 0;
}