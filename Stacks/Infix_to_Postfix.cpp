// Stack (Infix to Postfix)

 
// Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
// Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
// Why postfix representation of the expression? 
// The compiler scans the expression either from left to right or from right to left. 
// Consider the below expression: a op1 b op2 c op3 d 
// If op1 = +, op2 = *, op3 = +
// The compiler first scans the expression to evaluate the expression b * c, then again scans the expression to add a to it. The result is then added to d after another scan.
// The repeated scanning makes it very in-efficient. It is better to convert the expression to postfix(or prefix) form before evaluation.
// The corresponding expression in postfix form is abc*+d+. The postfix expressions can be evaluated easily using a stack. We will cover postfix expression evaluation in a separate post.


// Algorithm 
// 1. Scan the infix expression from left to right. 
// 2. If the scanned character is an operand, output it. 
// 3. Else, 
//       1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it. 
//       2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
// 4. If the scanned character is an ‘(‘, push it to the stack. 
// 5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
// 6. Repeat steps 2-6 until infix expression is scanned. 
// 7. Print the output 
// 8. Pop and output from the stack until it is not empty.



#include <iostream>
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
string infixToPostfix(string st)
{
    stack<char> s;
    string ans = "";
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
                if (st[i] == ')')
                {
                    while (s.size() != 0 && s.top() != '(')
                    {
                        ans = ans + s.top();
                        s.pop();
                    }
                    s.pop();
                }
                else if (s.size() != 0 && s.top() == '(')
                {
                    s.push(st[i]);
                }
                else if (prior(s.top()) < prior(st[i]))
                {
                    s.push(st[i]);
                }
                else
                {
                    while (s.size() != 0 && prior(s.top()) >= prior(st[i]))
                    {
                        ans = ans + s.top();
                        s.pop();
                        if (s.size() != 0 && s.top() == '(')
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
    return ans;
}
int main()
{
    string st;
    cout << "\n Enter the expression to be evaluated in the infix form:";
    cin >> st;
    string answer = infixToPostfix(st);
    cout << "\n The PostFix of the above Expression:" << answer;
    return 0;
}
