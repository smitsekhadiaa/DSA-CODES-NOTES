// Interleave the first half of the queue with second half
// Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

// Only a stack can be used as an auxiliary space.

// Examples:

// Input :  1 2 3 4
// Output : 1 3 2 4

// Input : 11 12 13 14 15 16 17 18 19 20
// Output : 11 16 12 17 13 18 14 19 15 20
// Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
// Following are the steps to solve the problem:
// 1.Push the first half elements of queue to stack.
// 2.Enqueue back the stack elements.
// 3.Dequeue the first half elements of the queue and enqueue them back.
// 4.Again push the first half elements into the stack.
// 5.Interleave the elements of queue and stack.


// C++ program to interleave the first half of the queue
// with the second half
#include <bits/stdc++.h>
using namespace std;
  
// Function to interleave the queue
void interLeaveQueue(queue<int>& q)
{
    // To check the even number of elements
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;
  
    // Initialize an empty stack of int type
    stack<int> s;
    int halfSize = q.size() / 2;
  
    // Push first half elements into the stack
    // queue:16 17 18 19 20, stack: 15(T) 14 13 12 11
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
  
    // enqueue back the stack elements
    // queue: 16 17 18 19 20 15 14 13 12 11
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
  
    // dequeue the first half elements of queue
    // and enqueue them back
    // queue: 15 14 13 12 11 16 17 18 19 20
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }
  
    // Again push the first half elements into the stack
    // queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
  
    // interleave the elements of queue and stack
    // queue: 11 16 12 17 13 18 14 19 15 20
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
  
// Driver program to test above function
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}