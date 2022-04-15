// Queue using two Stacks
// Implement a Queue using 2 stacks s1 and s2 .
// A Query Q is of 2 Types
// (i) 1 x (a query of this type means  pushing 'x' into the queue)
// (ii) 2   (a query of this type means to pop element from queue and print the poped element)

// Example 1:

// Input:
// 5
// 1 2 1 3 2 1 4 2

// Output:
// 2 3

// Explanation:
// In the first testcase
// 1 2 the queue will be {2}
// 1 3 the queue will be {2 3}
// 2   poped element will be 2 the queue
//     will be {3}
// 1 4 the queue will be {3 4}
// 2   poped element will be 3.
// Example 2:

// Input:
// 4
// 1 2 2 2 1 4

// Output:
// 2 -1

// Explanation:
// In the second testcase
// 1 2 the queue will be {2}
// 2   poped element will be 2 and
//     then the queue will be empty
// 2   the queue is empty and hence -1
// 1 4 the queue will be {4}.
// Your Task:
// You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the queue and pop which returns a integer poped out from other queue(-1 if the queue is empty). The printing is done automatically by the driver code.

// Expected Time Complexity : O(1) for push() and O(N) for pop() or O(N) for push() and O(1) for pop()
// Expected Auxilliary Space : O(1).

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

class StackQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int B);
    int pop();
};
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                sq->push(a);
            }
            else if (QueryType == 2)
            {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}
// } Driver Code Ends

/* The structure of the class is
class StackQueue{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

// Function to push an element in queue by using 2 stacks.
void StackQueue ::push(int x)
{
    // Your Code
    s1.push(x);
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue ::pop()
{
    // Your Code
    if (s2.size() == 0)
    {
        if (s1.size() == 0)
        {
            return -1;
        }
        else
        {
            while (!s1.size() == 0)
            {
                int a = s1.top();
                s1.pop();
                s2.push(a);
            }
        }
    }
    int b = s2.top();
    s2.pop();
    return b;
}

// ANALYSIS
// TIME: O(1) --> TO PUSH OR ENQUEUE
//       O(n) --> TO POP OR DEQUEUE

// SPACE: O(1)