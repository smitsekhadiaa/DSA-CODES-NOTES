// REMOVE DUPLICATE ELEMENTS FROM SORTED LINKED LIST

// { Driver Code Starts
// Initial Template for C
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} * start;

void insert();
void display(struct Node *head);

// } Driver Code Ends
// User function Template for C

void removeDuplicates(struct Node *head)
{
    struct Node *p, *q;
    p = head->next;
    q = head;
    while (p != NULL)
    {
        if (p->data != q->data) // if p's data is not equal to q's data; move forward in LL
        {
            q = p;
            p = p->next;
        }

        else // if both data equal; point q's next to p's next ,delete p to remove it from heap memory and bring p ahead of q for next comparison
        {
            q->next = p->next;
            delete p;
            p = q->next;
        }
    }
}
// ANALYSIS:
// 2 extra pointers required for comparing datas of linked list are repeated or not
// TIME COMPLEXITY: O(n) as we are traversing the entire linked list once from the while loop

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        start = NULL;
        insert();
        removeDuplicates(start);
        display(start);
        printf("\n");
    }
    return 0;
}

void insert()
{
    int n, value, i;
    scanf("%d", &n);
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (i == 0)
        {
            start = (struct Node *)malloc(sizeof(struct Node));
            start->data = value;
            start->next = NULL;
            temp = start;
            continue;
        }
        else
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

// } Driver Code Ends
