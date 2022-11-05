// // // https://leetcode.com/contest/weekly-contest-317/problems/most-popular-video-creator/

// // You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creator[i], has an id of ids[i], and has views[i] views.

// // The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.

// // If multiple creators have the highest popularity, find all of them.
// // If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
// // Return a 2D array of strings answer where answer[i] = [creatori, idi] means that creatori has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.

// // Example 1:

// // Input: creators = ["alice","bob","alice","chris"], ids = ["one","two","three","four"], views = [5,10,5,4]
// // Output: [["alice","one"],["bob","two"]]
// // Explanation:
// // The popularity of alice is 5 + 5 = 10.
// // The popularity of bob is 10.
// // The popularity of chris is 4.
// // alice and bob are the most popular creators.
// // For bob, the video with the highest view count is "two".
// // For alice, the videos with the highest view count are "one" and "three". Since "one" is lexicographically smaller than "three", it is included in the answer.
// // Example 2:

// // Input: creators = ["alice","alice","alice"], ids = ["a","b","c"], views = [1,2,2]
// // Output: [["alice","b"]]
// // Explanation:
// // The videos with id "b" and "c" have the highest view count.
// // Since "b" is lexicographically smaller than "c", it is included in the answer.

// class Solution
// {
// public:
//     struct video
//     {
//         long sum = 0;
//         string small;
//         int max_view = 0;
//     };

//     vector<vector<string>> mostPopularCreator(vector<string> &c, vector<string> &ids, vector<int> &views)
//     {
//         unordered_map<string, video> mp;
//         long count = 0;

//         for (int i = 0; i < size(c); i++)
//         {
//             // Check if creator present or not
//             if (!mp.count(c[i]))
//             {
//                 mp[c[i]] = {views[i], ids[i], views[i]};
//                 count = max(count, mp[c[i]].sum);
//                 continue;
//             }

//             // If already present , update all parameters as said in above algorithm
//             mp[c[i]].sum += views[i];
//             if (mp[c[i]].max_view < views[i] || mp[c[i]].max_view == views[i] && ids[i] < mp[c[i]].small)
//             {
//                 mp[c[i]].max_view = views[i];
//                 mp[c[i]].small = ids[i];
//             }

//             count = max(count, mp[c[i]].sum);
//         }

//         // extract words with highest count of views
//         vector<vector<string>> ans;
//         for (auto &r : mp)
//             if (r.second.sum == count)
//                 ans.push_back({r.first, r.second.small});

//         return ans;
//     }
// };