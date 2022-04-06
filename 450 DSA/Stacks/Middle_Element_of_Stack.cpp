// Design a stack with operations on middle element
// Difficulty Level : Medium
// Last Updated : 24 Nov, 2021
// How to implement a stack which will support following operations in O(1) time complexity? 
// 1) push() which adds an element to the top of stack. 
// 2) pop() which removes an element from top of stack. 
// 3) findMiddle() which will return middle element of the stack. 
// 4) deleteMiddle() which will delete the middle element. 
// Push and pop are standard stack operations. 
// The important question is, whether to use a linked list or array for the implementation of the stack? 
// Please note that we need to find and delete the middle element. Deleting an element from the middle is not O(1) for array. Also, we may need to move the middle pointer up when we push an element and move down when we pop(). In a singly linked list, moving the middle pointer in both directions is not possible. 
// The idea is to use Doubly Linked List (DLL). We can delete the middle element in O(1) time by maintaining mid pointer. We can move mid pointer in both directions using previous and next pointers. 
// Following is implementation of push(), pop() and findMiddle() operations. Implementation of deleteMiddle() is left as an exercise. If there are even elements in stack, findMiddle() returns the second middle element. For example, if stack contains {1, 2, 3, 4}, then findMiddle() would return 3. 
 




/* C++ Program to implement a stack
that supports findMiddle() and
deleteMiddle in O(1) time */


#include <bits/stdc++.h>
using namespace std;
 
class myStack

{
    struct Node
    {
        int num;
        Node *next;
        Node *prev;
 
        Node(int num)
        {
            this->num = num;
        }
    };
 
    //Members of stack
    Node *head = NULL;
    Node *mid = NULL;
    int size = 0;
 
public:
    void push(int data)
    {
        Node *temp = new Node(data);
        if (size==0)
        {
            head = temp;
            mid = temp;
            size++;
            return;
        }
 
        head->next = temp;
        temp->prev = head;
 
        //update the pointers
        head = head->next;
        if (size%2==1)
        {
            mid = mid->next;
        }
        size++;
    }
 
    void pop()
    {
        if (size!=0)
        {
            if (size==1)
            {
                head = NULL;
                mid = NULL;
            }
            else
            {
                head = head->prev;
                head->next = NULL;
                if (size%2==0)
                {
                    mid = mid->prev;
                }
            }
            size--;
        }
    }
 
    int findMiddle()
    {
        if (size==0)
        {
            return -1;
        }
        return mid->num;
    }
 
    void deleteMiddle()
    {
        if (size!=0)
        {
            if (size==1)
            {
                head = NULL;
                mid = NULL;
            }
            else if (size==2)
            {
                head = head->prev;
                mid = mid->prev;
                head->next =NULL;
            }
            else
            {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size%2==0)
                {
                    mid = mid->prev;
                }
                else
                {
                    mid = mid->next;
                }
            }
            size--;
        }
    }
};
 
 
int main()
{
    myStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.pop();
    st.pop();
    st.pop();
    cout<<st.findMiddle()<<endl;
    st.deleteMiddle();
    cout<<st.findMiddle()<<endl;
    return 0;
}