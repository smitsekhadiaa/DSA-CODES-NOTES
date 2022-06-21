// // 56. Merge Intervals
// // Medium

// // 14181

// // 533

// // Add to List

// // Share
// // Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// // Example 1:

// // Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// // Output: [[1,6],[8,10],[15,18]]
// // Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// // Example 2:

// // Input: intervals = [[1,4],[4,5]]
// // Output: [[1,5]]
// // Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// class Solution
// {
// public:
//     vector<vector<int>> merge(vector<vector<int>> &intervals)
//     {
//         stack<pair<int, int>> st;
//         sort(intervals.begin(), intervals.end());
//         st.push({intervals[0][0], intervals[0][1]});

//         for (int i = 0; i < intervals.size(); i++)
//         {
//             if (st.top().second >= intervals[i][0])
//             {
//                 pair<int, int> p = st.top();
//                 st.pop();
//                 p.second = max(p.second, intervals[i][1]);
//                 p.first = min(p.first, intervals[i][0]);
//                 st.push(p);
//             }
//             else
//             {
//                 st.push({intervals[i][0], intervals[i][1]});
//             }
//         }
//         vector<vector<int>> v;

//         while (!st.empty())
//         {
//             for (int i = 0; i < st.size(); i++)
//             {
//                 int x = st.top().first;
//                 int y = st.top().second;
//                 v.push_back({x, y});
//                 st.pop();
//             }
//         }
//         reverse(v.begin(), v.end());
//         return v;
//     }
// };