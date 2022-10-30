// 315. Count of Smaller Numbers After Self
// Hard

// 6720

// 187

// Add to List

// Share
// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

// Example 1:

// Input: nums = [5,2,6,1]
// Output: [2,1,1,0]
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
// Example 2:

// Input: nums = [-1]
// Output: [0]
// Example 3:

// Input: nums = [-1,-1]
// Output: [0,0]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

// SOLUTION::

// This question is related to count inversion, basically count inversion is which in we have to find two indices such that, i < j && arr[i] > arr[j]

// and here it is asking the count of smaller elements on right side of the array,
// so basically it is aksing the inversion count for each index of array.
// How?
// see, the element present in right side definately having the index greater than current index, and it asking for smaller elements so suppose current index is 'i' and take any right side index as 'j'
// then, since 'j' is present in right side so definately it is greater than i, so we can say that j > or i < j
// now, it is asking for smaller elements, so surely we can say that, arr[i] > arr[j],

// so, we found out that, i < j and arr[i] > arr[j]
// and it is nothing but the condition for count inversion, so question left is that,
// for each element we have to find the count inversion

// and in finding count inversion we used to apply merge sort technique
// so here also we apply merge sort technique on this

//   take an array, arr[] = [5, 2, 6, 1]
  
//     0 1 2 3 (index)
//     5 2 6 1 (array)
//       /\              mid = (0 + 3) / 2 = 3 / 2 = 1
//    0 1  2 3  (index)
//    5 2  6  1 (array)
//    /\    /\
//   0  1  2  3  (index)
//   5  2  6  1  (array)
  
//  1) One important thing we can observe here is, in doing merege sort
//      partition,
//      the partion of right is always having greater **index** than on left side index
  
//     see,             0 1 2 3 (index only)
//                       /   \
//     (left side)     0  1    2  3  (right side)  (left side index: (0, 1) & right side: (2,3) , here you can see rightSide indexes are greater than leftSide indexes) 
//                      /\      /\
//     (left side)     0  1    2  3 (right side)  ()
    
//                    0 < 1       2  < 3
//                  left  right  left   right
    
//  2) And in merge sort, hm ascending order main sort krte hain
//     but hm yahan desending order main sort krenge, aisa krne se 
//     hm easily count kr payenge
//     see, suppose a conditiion likes it:
   
//     i   j
//     0   1 2 3 (index)
//     5   6 3 2  (if i take it in decreasing order then i can say 5 4 3 2)
   
//     if(arr[i] > arr[j]) i.e 5 > 6 (false)
//     sorted array we make, put 6: sorted array: [6]
//     move j
   
//     i     j
//     0   1 2 3 (index)
//     5   6 3 2  (if i take it in decreasing order then i can say 5 4 3 2)
   
//     if(arr[i] > arr[j]) i.e 5 > 3 (true) so in answer at index 0 increase
//     but since hm array ko hm decreasing order main merge kr rhe hain,
//     toh hm jb merge krne jaynge, toh hm toh yeh definately jaante hain
//     ki hmari right side wali array definately decreasing order main sorted
//     hogi aur left side wali array bhi definately decreasing order main 
//     sorted hogi, aree ? 👍 merge sort main yhi hota hai na , bus yahan decreasing h
    
//     toh ab hme pta lga ki 5 > 3 hai, toh hm yeh definately kh skte hain ki
//     right side main ab jo 'j' ke aage array woh pkka hi 5 se choti hogi, 
//     toh bs 5 ke index ke liye ab hm direct answer nikal skte hain, ki kitni 
//     values hain,
//     so 5 ke liye hm kh skte hain ki (3, 2) yeh do values hain
//     see right side array, 6 3 2
    
//     so that's why hm decreasing order main sort kr rhe hain
// C++ Implementation :

// class Solution {
// public:

//     void merge(int left, int mid, int right, vector<pair<int, int>>& arr,vector<int>& count)
//     {
//         vector<pair<int, int>> temp(right - left + 1);
        
//         int i = left;
//         int j = mid + 1;
//         int k = 0;
        
//         while(i <= mid && j <= right)
//         {
//             if(arr[i].first <= arr[j].first)
//             {
//                 temp[k++] = arr[j++]; 
//             }
//             else
//             {
//                 count[arr[i].second] += (right - j + 1);
                
//                 temp[k++] = arr[i++];
//             }
//         }
        
//         while(i <= mid)
//         {
//             temp[k++] = arr[i++];
//         }
        
//         while(j <= right)
//         {
//             temp[k++] = arr[j++];
//         }
        
//         for(int l = left; l <= right; l++)
//         arr[l] = temp[l - left];
        
//     }
                
//     void mergeSort(int left, int right, vector<pair<int, int>>& arr, vector<int>& count)
//     {
//         if(left >= right)
//         {
//             return;
//         }

//         int mid = left + (right - left) / 2;
        
//         mergeSort(left, mid, arr, count);
//         mergeSort(mid + 1, right, arr, count);
        
//         merge(left, mid, right, arr, count);
//     }
    
// 	vector<int> countSmaller(vector<int>& nums) {
	    
//         int n=nums.size();
// 	    vector<pair<int, int>> arr;
        
// 	    for(int i = 0; i < n; i++)
// 	    {
// 	        arr.push_back({nums[i], i});
// 	    }
	    
// 	    vector<int> count(n, 0);
	    
// 	    mergeSort(0, n - 1, arr, count);
	    
// 	    return count;
// 	}
  
// };