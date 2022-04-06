// Expression contains redundant bracket or not
// Difficulty Level : Medium
// Last Updated : 14 Dec, 2021
// Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant, else ‘No’.
// Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.
// Example: 
 


// Explanation:
// 1. ((a+b)) can reduced to (a+b), this Redundant
// 2. (a+(b)/c) can reduced to (a+b/c) because b is
// surrounded by () which is redundant.
// 3. (a+b*(c-d)) doesn't have any redundant or multiple
// brackets.
 




// The idea is to use stack, which is discussed in this article. For any sub-expression of expression, if we are able to pick any sub-expression of expression surrounded by (), then we again left with () as part of string, we have redundant braces. 
// We iterate through the given expression and for each character in the expression, if the character is an open parenthesis ‘(‘ or any of the operators or operands, we push it to the stack. If the character is close parenthesis ‘)’, then pop characters from the stack till matching open parenthesis ‘(‘ is found. 
// Now for redundancy two condition will arise while popping- 
 

// If immediate pop hits an open parenthesis ‘(‘, then we have found a duplicate parenthesis. For example, (((a+b))+c) has duplicate brackets around a+b. When we reach the second “)” after a+b, we have “((” in the stack. Since the top of stack is an opening bracket, we conclude that there are duplicate brackets. 
 
// If immediate pop doesn’t hit any operand(‘*’, ‘+’, ‘/’, ‘-‘) then it indicates the presence of unwanted brackets surrounded by expression. For instance, (a)+b contain unwanted () around a thus it is redundant. 
 

 /* C++ Program to check whether valid
expression is redundant or not*/
#include <bits/stdc++.h>
using namespace std;

// Function to check redundant brackets in a
// balanced expression
bool checkRedundancy(string& str)
{
	// create a stack of characters
	stack<char> st;

	// Iterate through the given expression
	for (auto& ch : str) {

		// if current character is close parenthesis ')'
		if (ch == ')') {
			char top = st.top();
			st.pop();

			// If immediate pop have open parenthesis '('
			// duplicate brackets found
			bool flag = true;

			while (!st.empty() and top != '(') {

				// Check for operators in expression
				if (top == '+' || top == '-' ||
					top == '*' || top == '/')
					flag = false;

				// Fetch top element of stack
				top = st.top();
				st.pop();
			}

			// If operators not found
			if (flag == true)
				return true;
		}

		else
			st.push(ch); // push open parenthesis '(',
				// operators and operands to stack
	}
	return false;
}

// Function to check redundant brackets
void findRedundant(string& str)
{
	bool ans = checkRedundancy(str);
	if (ans == true)
		cout << "Yes\n";
	else
		cout << "No\n";
}

// Driver code
int main()
{
	string str = "((a+b))";
	findRedundant(str);

	str = "(a+(b)/c)";
	findRedundant(str);

	str = "(a+b*(c-d))";
	findRedundant(str);

	return 0;
}


// Input: 
// ((a+b))
// (a+(b)/c)
// (a+b*(c-d))

// Output: 
// Yes
// Yes
// No