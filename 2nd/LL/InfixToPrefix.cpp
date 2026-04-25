#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to return operator precedence
int prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    // Note: If you add '^' (exponentiation), its precedence would be 3
    return 0;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    // Step 1: Reverse infix
    reverse(infix.begin(), infix.end());

    // Step 2: Swap brackets
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    stack<char> s;
    string postfix = "";

    // Step 3: Modified Infix to Postfix
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // If operand, add to output
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // If '(', push to stack
        else if (ch == '(')
        {
            s.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop(); // Pop the '('
        }
        // If operator
        else
        {
            // CRITICAL FIX: Changed >= to > for left-associative operators
            while (!s.empty() && prec(s.top()) > prec(ch))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    // Step 4: Reverse postfix to get final prefix
    reverse(postfix.begin(), postfix.end());

    cout << "Prefix expression: " << postfix << endl;

    return 0;
}