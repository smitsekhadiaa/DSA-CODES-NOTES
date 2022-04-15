// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // Add code here
        Node *p = head;
        vector<int> v1, v2, v3;
        while (p != NULL)
        {

            if (p->data == 0)
            {
                v1.push_back(p->data);
                p = p->next;
            }
            else if (p->data == 1)
            {
                v2.push_back(p->data);
                p = p->next;
            }
            else
            {
                v3.push_back(p->data);
                p = p->next;
            }
        }
        p = head;
        while (p != NULL)
        {

            while (!v1.empty())
            {
                p->data = 0;
                p = p->next;
                v1.pop_back();
            }
            while (!v2.empty())
            {
                p->data = 1;
                p = p->next;
                v2.pop_back();
            }
            while (!v3.empty())
            {
                p->data = 2;
                p = p->next;
                v3.pop_back();
            }
        }
        return head;
    }
};
// ANALYSIS:
// TIME: O(n)
// SPACE: O(1)

// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1)
{
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main()
{

    int n;

    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
} // } Driver Code Ends