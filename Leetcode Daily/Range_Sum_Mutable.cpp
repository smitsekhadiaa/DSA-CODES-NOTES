// // 307. Range Sum Query - Mutable
// // Medium

// // 3578

// // 183

// // Add to List

// // Share
// // Given an integer array nums, handle multiple queries of the following types:

// // Update the value of an element in nums.
// // Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// // Implement the NumArray class:

// // NumArray(int[] nums) Initializes the object with the integer array nums.
// // void update(int index, int val) Updates the value of nums[index] to be val.
// // int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

// // Example 1:

// // Input
// // ["NumArray", "sumRange", "update", "sumRange"]
// // [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// // Output
// // [null, 9, null, 8]

// // Explanation
// // NumArray numArray = new NumArray([1, 3, 5]);
// // numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// // numArray.update(1, 2);   // nums = [1, 2, 5]
// // numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
// class NumArray
// {
// public:
//     vector<int> v;
//     int sum;
//     NumArray(vector<int> &nums)
//     {
//         v = nums;
//         sum = 0;
//         for (int i = 0; i < v.size(); i++)
//         {
//             sum += v[i];
//         }
//     }

//     void update(int index, int val)
//     {
//         sum = sum - v[index];
//         v[index] = val;
//         sum += val;
//     }

//     int sumRange(int left, int right)
//     {

//         int res = sum;
//         for (int i = 0; i < left; i++)
//         {
//             res = res - v[i];
//         }

//         for (int i = right + 1; i < v.size(); i++)
//         {
//             res = res - v[i];
//         }
//         return res;
//     }
// };

// /**
//  * Your NumArray object will be instantiated and called as such:
//  * NumArray* obj = new NumArray(nums);
//  * obj->update(index,val);
//  * int param_2 = obj->sumRange(left,right);
//  */