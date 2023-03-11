// // Linked List Random Node
// // Medium
// // 2.8K
// // 664
// // Companies
// // Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

// // Implement the Solution class:

// // Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
// // int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.
 

// // Example 1:


// // Input
// // ["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
// // [[[1, 2, 3]], [], [], [], [], []]
// // Output
// // [null, 1, 3, 2, 2, 3]

// // Explanation
// // Solution solution = new Solution([1, 2, 3]);
// // solution.getRandom(); // return 1
// // solution.getRandom(); // return 3
// // solution.getRandom(); // return 2
// // solution.getRandom(); // return 2
// // solution.getRandom(); // return 3
// // // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
 

// // Constraints:

// // The number of nodes in the linked list will be in the range [1, 104].
// // -104 <= Node.val <= 104
// // At most 104 calls will be made to getRandom.
 
//  /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */


// class Solution {
// private:
//     ListNode* head;
    
// public:
//     Solution(ListNode* head) {
//         this->head = head;
//         std::srand(std::time(0)); // seed the random number generator
//     }
    
//     int getRandom() {
//         int count = 0;
//         int result = 0;
//         ListNode* curr = head;
        
//         while (curr) {
//             count++;
//             // generate a random number between 1 and the count
//             // if the random number is 1, update the result with the current node's value
//             if (std::rand() % count == 0) {
//                 result = curr->val;
//             }
//             curr = curr->next;
//         }
        
//         return result;
//     }
// };
// /**
//  * Your Solution object will be instantiated and called as such:
//  * Solution* obj = new Solution(head);
//  * int param_1 = obj->getRandom();
//  */