// Minimum Genetic Mutation
// Medium

// 2026

// 209

// Add to List

// Share
// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

// Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

// Example 1:

// Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
// Output: 1
// Example 2:

// Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2
// Example 3:

// Input: start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
// Output: 3
 

// Constraints:

// start.length == 8
// end.length == 8
// 0 <= bank.length <= 10
// bank[i].length == 8
// start, end, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].


// class Solution
// {
// public:
//     int minMutation(string start, string end, vector<string> &bank)
//     {
//         // a queue to store each gene string (node)
//         queue<string> q;
//         // a hash map to store if we've visited a node
//         unordered_map<string, int> vis;
//         // distance
//         int steps = 0;
//         // we start from gene string `start` as a starting point
//         // push it to the queue
//         q.push(start);
//         // and mark it visited
//         vis[start] = 1;
//         // BFS
//         while (!q.empty())
//         {
//             // iterate from the back because the size of q varies
//             // which would result in wrong answer if you iterate from 0
//             // alternatively, you can define a new variable for q.size() before the for-loop
//             // i.e.
//             // int n = q.size();
//             // for (int i = 0; i < n; i++) {
//             for (int i = q.size(); i > 0; i--)
//             {
//                 // get the gene string from the queue
//                 string s = q.front();
//                 q.pop();
//                 // if it is same as `end`, that means we found the answer
//                 if (s == end)
//                     return steps;
//                 // otherwise, given a gene string with 8-character long
//                 // we can replace each character with "A", "C", "G" and "T" (i.e. mutate)
//                 for (int j = 0; j < 8; j++)
//                 {
//                     // s[j] will be modified later,
//                     // hence store the original character here
//                     char oc = s[j];
//                     // iterate ACGT
//                     // alternatively, you can use `for (char c : "ACGT") { ... }`
//                     for (int k = 0; k < 4; k++)
//                     {
//                         // replace the j-th character in s with the k-th character in ACGT
//                         s[j] = "ACGT"[k];
//                         // we can reach the next node if the next node hasn't been visited
//                         // and the next node is available in `bank`
//                         if (!vis[s] && find(bank.begin(), bank.end(), s) != bank.end())
//                         {
//                             // push the next node to the queue
//                             q.push(s);
//                             // and mark it visited
//                             vis[s] = 1;
//                         }
//                     }
//                     // since we updated the character, we revert it back
//                     s[j] = oc;
//                 }
//             }
//             // increase the step count
//             steps += 1;
//         }
//         // not able to reach `end`, return -1 here
//         return -1;
//     }
// };