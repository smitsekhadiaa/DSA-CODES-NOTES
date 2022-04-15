// Return the middle element of linked list if there are 2 middle elements then return the second element

/**
 * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode *p;
//         p=head;
//         int count=0;
//         while(p->next!=NULL)
//         {
//             count++;
//             p=p->next;
//         }
//         if(count%2==0)
//         {
//             count=count/2;
//         }
//         else
//         {
//             count=count/2;
//             count=count+1;
//         }
//         p=head;
//         for(int i=0;i<count;i++)
//         {
//             p=p->next;

//         }
//         return p;
//     }
// };