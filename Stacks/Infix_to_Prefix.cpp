// Convert Infix To Prefix Notation

// While we use infix expressions in our day to day lives. Computers have trouble understanding this format because they need to keep in mind rules of operator precedence and also brackets. Prefix and Postfix expressions are easier for a computer to understand and evaluate.
// Given two operands a and b and an operator \odot  , the infix notation implies that O will be placed in between a and b i.e a \odot b. When the operator is placed after both operands i.e ab\odot , it is called postfix notation. And when the operator is placed before the operands i.e \odot a b  , the expression in prefix notation.
// Given any infix expression, we can obtain the equivalent prefix and postfix format.

// Examples:

// Input : A * B + C / D
// Output : + * A B/ C D

// Input : (A - B/C) * (A/K-L)
// Output : *-A/BC-/AKL
// To convert an infix to postfix expression refer to this article Stack | Set 2 (Infix to Postfix). We use the same to convert Infix to Prefix.

// Step 1: Reverse the infix expression i.e A+B*C will become C*B+A. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
// Step 2: Obtain the “nearly” postfix expression of the modified expression i.e CB*A+.
// Step 3: Reverse the postfix expression. Hence in our example prefix is +A*BC.
// Note that for Step 2, we don’t use the postfix algorithm as it is. There is a minor change in the algorithm. As per , we have to pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. But here, we have to pop all the operators from the stack which are greater in precedence than that of the scanned operator. Only in the case of “^” operator, we pop operators from the stack which are greater than or equal to in precedence.

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int prior(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
bool operate(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}
string infixToPrefix(string st)
{
    stack<char> s;
    string ans = "";
    reverse(st.begin(), st.end());
    for (int i = 0; i < st.length(); i++)
    {
        if (operate(st[i]) == false)
        {
            ans = ans + st[i];
        }
        else
        {
            if (s.size() == 0)
            {
                s.push(st[i]);
            }
            else
            {
                if (st[i] == '(')
                {
                    while (s.size() != 0 && s.top() != ')')
                    {
                        ans = ans + s.top();
                        s.pop();
                    }
                    s.pop();
                }
                else if (s.top() == ')')
                {
                    s.push(st[i]);
                }
                else if (prior(s.top()) <= prior(st[i]))
                {
                    s.push(st[i]);
                }
                else
                {
                    while (s.size() != 0 && prior(s.top()) > prior(st[i]))
                    {
                        ans = ans + s.top();
                        s.pop();
                        if (s.size() != 0 && s.top() == ')')
                        {
                            break;
                        }
                    }
                    s.push(st[i]);
                }
            }
        }
    }
    while (s.size() != 0)
    {
        ans = ans + s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string st;
    cout << "\n Enter the expression to be evaluated in the infix form:";
    cin >> st;
    string answer = infixToPrefix(st);
    cout << "\n The PreFix of the above Expression:" << answer;
    return 0;
}
