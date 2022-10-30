// // // 240. Search a 2D Matrix II

// // // Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// // // Integers in each row are sorted in ascending from left to right.
// // // Integers in each column are sorted in ascending from top to bottom.

// // // Example 1:

// // // Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// // // Output: true
// // // Example 2:

// // // Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// // // Output: false

// // // Constraints:

// // // m == matrix.length
// // // n == matrix[i].length
// // // 1 <= n, m <= 300
// // // -109 <= matrix[i][j] <= 109
// // // All the integers in each row are sorted in ascending order.
// // // All the integers in each column are sorted in ascending order.
// // // -109 <= target <= 109

// // EFFICIENT APPROACH -> O ( M + N )

// // As the rows are sorted -> matrix[i][j] < matrix[i][j+1]
// // As the columns are sorted -> matrix[i][j] >matrix[i-1][j]

// // Hence it can be said that :

// // any element right to matrix[i][j] will be greater than it.
// // any element to the top of matrix[i][j] will be less than it.
// // So we start searching from BOTTOM_LEFT:

// // if element found -> return TRUE
// // if matrix[i][j] > target -> move UP.
// // if matrix[i][j] < target -> move RIGHT.
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& mat, int target) {

//         int m = mat.size();
//         int n = mat[0].size();

//         int i = m - 1;
//         int j = 0;

//         while (i>=0 && j<n){

//             if (mat[i][j] == target) return true;

//             else if (mat[i][j] < target) j++;

//             else i--;
//         }
//         return false;

//     }
// };