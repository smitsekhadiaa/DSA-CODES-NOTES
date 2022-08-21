// // 936. Stamping The Sequence
// // Hard

// // 1027

// // 171

// // Add to List

// // Share
// // You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.

// // In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.

// // For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
// // place stamp at index 0 of s to obtain "abc??",
// // place stamp at index 1 of s to obtain "?abc?", or
// // place stamp at index 2 of s to obtain "??abc".
// // Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
// // We want to convert s to target using at most 10 * target.length turns.

// // Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.

 

// // Example 1:

// // Input: stamp = "abc", target = "ababc"
// // Output: [0,2]
// // Explanation: Initially s = "?????".
// // - Place stamp at index 0 to get "abc??".
// // - Place stamp at index 2 to get "ababc".
// // [1,0,2] would also be accepted as an answer, as well as some other answers.
// // Example 2:

// // Input: stamp = "abca", target = "aabcaca"
// // Output: [3,0,1]
// // Explanation: Initially s = "???????".
// // - Place stamp at index 3 to get "???abca".
// // - Place stamp at index 0 to get "abcabca".
// // - Place stamp at index 1 to get "aabcaca".
 
// class Solution {
// public:
//     bool canReplace(string &stamp,string &target,int pos){
//         int m=stamp.size(),n=target.size();
//         for(int i=0;i<m;i++){
//             if(target[i+pos]!='?' and target[i+pos]!=stamp[i])
//                 return false;
//         }
//         return true;
//     }
    
    
//     int replace(string &stamp,string &target,int pos){
//         int cnt=0;
//         int m=stamp.size(),n=target.size();
//         for(int i=0;i<m;i++){
//             if(target[i+pos]!='?'){
//                 cnt++;
//                 target[i+pos]='?';
//             }
//         }
//         return cnt;
//     }
    
//     vector<int> movesToStamp(string stamp, string target) {
        
//         vector<int> ans;
        
//         int m=stamp.size(),n=target.size();
        
//         int count=0;
        
//         vector<int> vis(n+1,0);
        
//         while(count!=n){
//             bool flag=false;
//             for(int i=0;i<=n-m;i++){
//                 if(!vis[i] and canReplace(stamp,target,i)){
//                     vis[i]=1;
//                     count+=replace(stamp,target,i);
//                     flag=true;
//                     ans.push_back(i);
//                     if(count==n) break;
//                 }
//             }
//             if(!flag) return {};
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };
