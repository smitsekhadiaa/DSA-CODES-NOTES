// Stack Permutations (Check if an array is stack permutation of other)

// A stack permutation is a permutation of objects in the given input queue which is done by transferring elements from input queue to the output queue with the help of a stack and the built-in push and pop functions.
// The well defined rules are:

// Only dequeue from the input queue.
// Use inbuilt push, pop functions in the single stack.
// Stack and input queue must be empty at the end.
// Only enqueue to the output queue.
// There are a huge number of permutations possible using a stack for a single input queue.
// Given two arrays, both of unique elements. One represents the input queue and the other represents the output queue. Our task is to check if the given output is possible through stack permutation.
// Examples:

// Input : First array: 1, 2, 3
//         Second array: 2, 1, 3
// Output : Yes
// Procedure:
// push 1 from input to stack
// push 2 from input to stack
// pop 2 from stack to output
// pop 1 from stack to output
// push 3 from input to stack
// pop 3 from stack to output

// Input : First array: 1, 2, 3
//         Second array: 3, 1, 2
// Output : Not Possible

// Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
// The idea to do this is we will try to convert the input queue to output queue using a stack, if we are able to do so then the queue is permutable otherwise not.
// Below is the step by step algorithm to do this:

// Continuously pop elements from the input queue and check if it is equal to the top of output queue or not, if it is not equal to the top of output queue then we will push the element to stack.

// Once we find an element in input queue such the top of input queue is equal to top of output queue, we will pop a single element from both input and output queues, and compare the top of stack and top of output queue now. If top of both stack and output queue are equal then pop element from both stack and output queue. If not equal, go to step 1.

// Repeat above two steps until the input queue becomes empty. At the end if both of the input queue and stack are empty then the input queue is permutable otherwise not.

// Given two arrays, check if one array is
// stack permutation of other.
#include <bits/stdc++.h>
using namespace std;

// function to check if input queue is
// permutable to output queue
bool checkStackPermutation(int ip[], int op[], int n)
{
	// Input queue
	queue<int> input;
	for (int i = 0; i < n; i++)
		input.push(ip[i]);

	// output queue
	queue<int> output;
	for (int i = 0; i < n; i++)
		output.push(op[i]);

	// stack to be used for permutation
	stack<int> tempStack;
	while (!input.empty())
	{
		int ele = input.front();
		input.pop();
		if (ele == output.front())
		{
			output.pop();
			while (!tempStack.empty())
			{
				if (tempStack.top() == output.front())
				{
					tempStack.pop();
					output.pop();
				}
				else
					break;
			}
		}
		else
			tempStack.push(ele);
	}

	// If after processing, both input queue and
	// stack are empty then the input queue is
	// permutable otherwise not.
	return (input.empty() && tempStack.empty());
}

// Driver program to test above function
int main()
{
	// Input Queue
	int input[] = {1, 2, 3};

	// Output Queue
	int output[] = {2, 1, 3};

	int n = 3;

	if (checkStackPermutation(input, output, n))
		cout << "Yes";
	else
		cout << "Not Possible";
	return 0;
}
