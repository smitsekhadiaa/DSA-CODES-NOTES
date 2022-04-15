// Maximum size rectangle binary sub-matrix with all 1s

// Given a binary matrix mat[][] of size N*M, find the maximum size rectangle binary-sub-matrix with all 1’s.

// Input: mat[][] =                 { {0, 1, 1, 0}, 
//                                    {1, 1, 1, 1}, 
//                                    {1, 1, 1, 1}, 
//                                    {1, 1, 0, 0} }
// Output: 8


// Explanation: The largest rectangle formed with only 1s is either: (0, 1) to (2, 2) or (1, 1) to (2, 3)  which is
// 1 1 1 1
// 1 1 1 1

// Input: mat[][] =              { {0, 1, 1}, 
//                                 {1, 1, 1}, 
//                                 {0, 1, 1} }

// Output: 6


// Explanation: The largest rectangle with only 1’s is from (0, 1) to (2, 2) which is
// 1 1
// 1 1
// 1 1

 


// Approach: 
// This approach uses the concept of Largest Rectangular Area in Histogram. But the approach to get the maximum area for each row will be different than Set-1. 

// Consider each row as the base of the histogram chart formed with all 1s.
// For each row, increase height of a bar by the amount of the previous row, only if the value in current row is 1 and calculate the largest rectangular area of that histogram.
// The largest rectangular area of a histogram among all possible base rows is the required are of the rectangle.
// Illustration:

// Consider the matrix:
// mat[][] =         0 1 1 0
//                   1 1 1 1
//                   1 1 1 1
//                   1 1 0 0 

// Calculate maxarea for the first row mat[0]
//         => height row[0] = 0 1 1 0. 
//         => area  = height* breadth = 1 * 2 = 2

// Calculate maxarea for the first row mat[1]
//         => update height of mat[1] with mat[0] i.e., mat[1][i] = mat[0][i] + 1 if mat[1][i] = 1, else 0
//         => height row[1] = 1 2 2 1. 
//         => area  = height* breadth = 2 * 2 = 4

// Calculate maxarea for the first row mat[2]
//         => update height of mat[2] with mat[1]. i.e., mat[2][i] = mat[1][i] + 1 if mat[2][i] = 1, else 0.
//         => height row[2] = 2 3 3 2. 
//         => area  = height* breadth = 2 * 4 = 8 (nextsmaller index of mat[2][0] = 4, and previous smaller index = 0. area = 2*(4 – 0))

// Calculate maxarea for the first row mat[3]
//         => update height of mat[3] with mat[2]. i.e., mat[3][i] = mat[2][i] + 1 if mat[3][i] = 1, else 0.
//         => height row[3] = 3 4 0 0. 
//         => area  = height* breadth = 3 * 2 = 6 (nextsmaller index of mat[3][0] = 2, and previous smaller index = 0. area = 3*(2 – 0))
//         => here 3 4 0 0 is due to the reason that when mat[i][j] = 0 then don’t add previous heights into it. 

// Thus maxarea = max of(2, 4, 8, 6) = 8.

// This approach can be broken into two parts: 

// Calculate heights of histogram for each row as base. 
// Run a loop to traverse through the rows.
// Now If the current row is not the first row then update the height for that cell as follows,  
// If mat[i][j] is not zero then matrix[i][j] = matrix[i-1][j] + matrix[i][j]. 
// Else mat[i][j] = 0.
// Calculate largest rectangular area in histogram of 1s for each row as base.
// First calculate the heights for each row as base as mentioned above.
// Create two arrays nextSmallereElemen[] and previouSmallerElement[] to store the indices of previous smaller elements and next smaller elements respectively. Refer to this article to find the previous and next smaller element.
// Now for every element, calculate area by taking this jth element as the smallest in the range nextSmallereElemen[j]  and previouSmallerElement[j] and multiplying it with the difference of nextSmallereElemen[j]  and previouSmallerElement[j]. 
// So, height will be the jth element in the given input array. And breadth will be, breadth = nextSmallereElemen[j] – previouSmallerElement[j].
// Finally, find the maximum of all the areas to get the desired maximum area.
// Find the maximum areas among all the rows, and that will be the required area of the rectangle.

// C++ code for the above approach:

// #include <bits/stdc++.h>
// using namespace std;

// // Function to find next smaller element
// vector<int> nextsmallerelement(vector<int>& arr,
// 							int n)
// {

// 	stack<int> st;

// 	// For the elements which dont have
// 	// next smaller element ans will be -1
// 	st.push(-1);

// 	// Store indices in output
// 	vector<int> right(n);

// 	// Start from last index
// 	for (int i = n - 1; i >= 0; i--) {

// 		// If top element is sorted then
// 		// no need to do anyrhing, just store
// 		// the answer and push the
// 		// current element in stack
// 		if ((st.top() != -1)
// 			&& arr[st.top()] < arr[i]) {
// 			right[i] = st.top();
// 			st.push(i);
// 		}
// 		else {
// 			while ((st.top() != -1)
// 				&& arr[st.top()]
// 						>= arr[i]) {
// 				st.pop();
// 			}
// 			right[i] = st.top();
// 			st.push(i);
// 		}
// 	}
// 	return right;
// }

// // Function to find previous smaller element
// vector<int> previousmallerelement(vector<int>& arr,
// 								int n)
// {
// 	stack<int> st;
// 	st.push(-1);
// 	vector<int> left(n);

// 	// Start from first index
// 	for (int i = 0; i < n; i++) {
// 		if ((st.top() != -1)
// 			&& arr[st.top()] < arr[i]) {
// 			left[i] = st.top();
// 			st.push(i);
// 		}
// 		else {
// 			while ((st.top() != -1)
// 				&& arr[st.top()]
// 						>= arr[i]) {
// 				st.pop();
// 			}
// 			left[i] = st.top();
// 			st.push(i);
// 		}
// 	}
// 	return left;
// }

// // Function to get the maximum area
// // considering each row as the histogram base
// int getMaxArea(vector<int>& arr, int n)
// {
// 	vector<int> right(n);
// 	right = nextsmallerelement(arr, n);

// 	// Find the smallest element than
// 	// curr element in right side

// 	vector<int> left(n);
// 	left = previousmallerelement(arr, n);

// 	// Find the smallest element
// 	// than curr element in left side
// 	int maxarea = INT_MIN;

// 	// Now the left and right vector have
// 	// index of smallest elemnt in left and
// 	// right respetively, thus the difference
// 	// of right - left - 1 will give us
// 	// breadth and thus
// 	// area = height(curr==arr[i]) * breadth;
// 	for (int i = 0; i < n; i++) {
// 		int height = arr[i];
// 		if (right[i] == -1) {
// 			right[i] = n;
// 		}
// 		int breadth = right[i] - left[i] - 1;
// 		maxarea = max(maxarea,
// 					height * breadth);
// 	}
// 	return maxarea;
// }

// // Function to calculate
// // the maximum area of rectangle
// int maxRectangleArea(vector<vector<int> >& M,
// 					int n, int m)
// {

// 	// Calculate maxarea for first row
// 	int area = getMaxArea(M[0], m);
// 	int maxarea = area;

// 	for (int i = 1; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			if (M[i][j] != 0) {

// 				// Add heights of previous rows
// 				// into current
// 				M[i][j] = M[i][j]
// 						+ M[i - 1][j];
// 			}
// 			else {

// 				// If current height is 0 then
// 				// don't add previous heights
// 				M[i][j] = 0;
// 			}
// 		}
// 		maxarea = max(maxarea,
// 					getMaxArea(M[i], m));
// 	}
// 	return maxarea;
// }

// // Driver code
// int main()
// {
// 	int N = 4, M = 4;
// 	vector<vector<int> > amt = {
// 		{ 0, 1, 1, 0 },
// 		{ 1, 1, 1, 1 },
// 		{ 1, 1, 1, 1 },
// 		{ 1, 1, 0, 0 },
// 	};

// 	cout << maxRectangleArea(amt, N, M);
// 	return 0;
// }

// Time Complexity: O(N * M)
// Auxiliary Space: O(M)


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int MAH(int arr[], int n)
    {
        // Your code here
        stack<pair<int, int> > s1;
        stack<pair<int, int> > s2;
        vector<int> nsr;
        vector<int> nsl;
        vector<int> mah;
        for(int i=n;i>=0;i--){
            while(s1.size()>0 && s1.top().first>=arr[i]){
                s1.pop();
            }
            if(s1.empty()){
                nsr.push_back(n);
            }
            else if(s1.top().first < arr[i]) nsr.push_back(s1.top().second);
            s1.push( make_pair(arr[i],i) );   
        }
        reverse(nsr.begin(), nsr.end());
        
        for(int i=0;i<n;i++){
            while(s2.size()>0 && s2.top().first>=arr[i]){
                s2.pop();
            }
            if(s2.empty()){
                nsl.push_back(-1);
            }
            else if(s2.top().first < arr[i]) nsl.push_back(s2.top().second);
            s2.push( make_pair(arr[i],i) );   
        }
        
        int maxi =0, b=0;
        for(int i=0;i<n;i++){
            b = arr[i]*(nsr[i]-nsl[i]-1);
            if(b>maxi) 
                maxi=b;
        }
        return maxi;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
         int v[m]={0};
        for(int j = 0;j<m;j++){
            v[j]=M[0][j];
        }
        int maxi = MAH(v,m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0) v[j]=0;
                else v[j]+=1;
            }
            maxi=max(maxi, MAH(v,m));
        }
        return maxi;
        
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends