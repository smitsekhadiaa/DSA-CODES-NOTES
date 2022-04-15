// How to efficiently implement k Queues in a single array?

// We have discussed efficient implementation of k stack in an array. In this post, same for queue is discussed. Following is the detailed problem statement.

// Create a data structure kQueues that represents k queues. Implementation of kQueues should use only one array, i.e., k queues should use the same array for storing elements. Following functions must be supported by kQueues.
// enqueue(int x, int qn) –> adds x to queue number ‘qn’ where qn is from 0 to k-1 
// dequeue(int qn) –> deletes an element from queue number ‘qn’ where qn is from 0 to k-1 
// Method 1 (Divide the array in slots of size n/k) 
// A simple way to implement k queues is to divide the array in k slots of size n/k each, and fix the slots for different queues, i.e., use arr[0] to arr[n/k-1] for the first queue, and arr[n/k] to arr[2n/k-1] for queue2 where arr[] is the array to be used to implement two queues and size of array be n.
// The problem with this method is an inefficient use of array space. An enqueue operation may result in overflow even if there is space available in arr[]. For example, consider k as 2 and array size n as 6. Let we enqueue 3 elements to first and do not enqueue anything to the second queue. When we enqueue the 4th element to the first queue, there will be overflow even if we have space for 3 more elements in the array.



// Method 2 (A space efficient implementation) 
// The idea is similar to the stack post, here we need to use three extra arrays. In stack post, we needed two extra arrays, one more array is required because in queues, enqueue() and dequeue() operations are done at different ends.
// Following are the three extra arrays are used: 
// 1) front[]: This is of size k and stores indexes of front elements in all queues. 
// 2) rear[]: This is of size k and stores indexes of rear elements in all queues. 
// 2) next[]: This is of size n and stores indexes of next item for all items in array arr[]. 
// Here arr[] is the actual array that stores k stacks.
// Together with k queues, a stack of free slots in arr[] is also maintained. The top of this stack is stored in a variable ‘free’.
// All entries in front[] are initialized as -1 to indicate that all queues are empty. All entries next[i] are initialized as i+1 because all slots are free initially and pointing to the next slot. Top of the free stack, ‘free’ is initialized as 0.
// Following is C++ implementation of the above idea. 

// A C++ program to demonstrate implementation of k queues in a single
// array in time and space efficient way
#include<iostream>
#include<climits>
using namespace std;

// A C++ class to represent k queues in a single array of size n
class kQueues
{
	// Array of size n to store actual content to be stored in queue
	int *arr;

	// Array of size k to store indexes of front elements of the queue
	int *front;

	// Array of size k to store indexes of rear elements of queue
	int *rear;

	// Array of size n to store next entry in all queues		
	int *next;
	int n, k;

	int free; // To store the beginning index of the free list

public:
	//constructor to create k queue in an array of size n
	kQueues(int k, int n);

	// A utility function to check if there is space available
	bool isFull() { return (free == -1); }

	// To enqueue an item in queue number 'qn' where qn is from 0 to k-1
	void enqueue(int item, int qn);

	// To dequeue an from queue number 'qn' where qn is from 0 to k-1
	int dequeue(int qn);

	// To check whether queue number 'qn' is empty or not
	bool isEmpty(int qn) { return (front[qn] == -1); }
};

// Constructor to create k queues in an array of size n
kQueues::kQueues(int k1, int n1)
{
	// Initialize n and k, and allocate memory for all arrays
	k = k1, n = n1;
	arr = new int[n];
	front = new int[k];
	rear = new int[k];
	next = new int[n];

	// Initialize all queues as empty
	for (int i = 0; i < k; i++)
		front[i] = -1;

	// Initialize all spaces as free
	free = 0;
	for (int i=0; i<n-1; i++)
		next[i] = i+1;
	next[n-1] = -1; // -1 is used to indicate end of free list
}

// To enqueue an item in queue number 'qn' where qn is from 0 to k-1
void kQueues::enqueue(int item, int qn)
{
	// Overflow check
	if (isFull())
	{
		cout << "\nQueue Overflow\n";
		return;
	}

	int i = free;	 // Store index of first free slot

	// Update index of free slot to index of next slot in free list
	free = next[i];

	if (isEmpty(qn))
		front[qn] = i;
	else
		next[rear[qn]] = i;

	next[i] = -1;

	// Update next of rear and then rear for queue number 'qn'
	rear[qn] = i;

	// Put the item in array
	arr[i] = item;
}

// To dequeue an from queue number 'qn' where qn is from 0 to k-1
int kQueues::dequeue(int qn)
{
	// Underflow checkSAS
	if (isEmpty(qn))
	{
		cout << "\nQueue Underflow\n";
		return INT_MAX;
	}

	// Find index of front item in queue number 'qn'
	int i = front[qn];

	front[qn] = next[i]; // Change top to store next of previous top

	// Attach the previous front to the beginning of free list
	next[i] = free;
	free = i;

	// Return the previous front item
	return arr[i];
}

/* Driver program to test kStacks class */
int main()
{
	// Let us create 3 queue in an array of size 10
	int k = 3, n = 10;
	kQueues ks(k, n);

	// Let us put some items in queue number 2
	ks.enqueue(15, 2);
	ks.enqueue(45, 2);

	// Let us put some items in queue number 1
	ks.enqueue(17, 1);
	ks.enqueue(49, 1);
	ks.enqueue(39, 1);

	// Let us put some items in queue number 0
	ks.enqueue(11, 0);
	ks.enqueue(9, 0);
	ks.enqueue(7, 0);

	cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
	cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
	cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

	return 0;
}

// ANALYSIS: 
// TIME : ENQUEUE AND DEQUEUE : O(1)
// SPACE: O(n)
