// 2 METHODS: USING 2 STACKS AND USING 1 STACK

// Iterative Postorder Traversal (Using Two Stacks)

// We have discussed iterative inorder and iterative preorder traversals. In this post, iterative postorder traversal is discussed, which is more complex than the other two traversals (due to its nature of non-tail recursion, there is an extra statement after the final recursive call to itself). Postorder traversal can easily be done using two stacks, though. The idea is to push reverse postorder traversal to a stack. Once we have the reversed postorder traversal in a stack, we can just pop all items one by one from the stack and print them; this order of printing will be in postorder because of the LIFO property of stacks. Now the question is, how to get reversed postorder elements in a stack – the second stack is used for this purpose. For example, in the following tree, we need to get 1, 3, 7, 6, 2, 5, 4 in a stack. If take a closer look at this sequence, we can observe that this sequence is very similar to the preorder traversal. The only difference is that the right child is visited before left child, and therefore the sequence is “root right left” instead of “root left right”. So, we can do something like iterative preorder traversal with the following differences:

// a) Instead of printing an item, we push it to a stack.
// b) We push the left subtree before the right subtree.
// Following is the complete algorithm. After step 2, we get the reverse of a postorder traversal in the second stack. We use the first stack to get the correct order.

// 1. Push root to first stack.
// 2. Loop while first stack is not empty
//    2.1 Pop a node from first stack and push it to second stack
//    2.2 Push left and right children of the popped node to first stack
// 3. Print contents of second stack
// Let us consider the following tree

// Following are the steps to print postorder traversal of the above tree using two stacks.

// 1. Push 1 to first stack.
//       First stack: 1
//       Second stack: Empty

// 2. Pop 1 from first stack and push it to second stack.
//    Push left and right children of 1 to first stack
//       First stack: 2, 3
//       Second stack: 1

// 3. Pop 3 from first stack and push it to second stack.
//    Push left and right children of 3 to first stack
//       First stack: 2, 6, 7
//       Second stack: 1, 3

// 4. Pop 7 from first stack and push it to second stack.
//       First stack: 2, 6
//       Second stack: 1, 3, 7

// 5. Pop 6 from first stack and push it to second stack.
//       First stack: 2
//       Second stack: 1, 3, 7, 6

// 6. Pop 2 from first stack and push it to second stack.
//    Push left and right children of 2 to first stack
//       First stack: 4, 5
//       Second stack: 1, 3, 7, 6, 2

// 7. Pop 5 from first stack and push it to second stack.
//       First stack: 4
//       Second stack: 1, 3, 7, 6, 2, 5

// 8. Pop 4 from first stack and push it to second stack.
//       First stack: Empty
//       Second stack: 1, 3, 7, 6, 2, 5, 4

// The algorithm stops here since there are no more items in the first stack.
// Observe that the contents of second stack are in postorder fashion. Print them.

#include <bits/stdc++.h>
using namespace std;

// A tree node
struct Node
{

    int data;
    Node *left, *right;
};

// Function to create a new node with the given data
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// An iterative function to do post order
// traversal of a given binary tree
void postOrderIterative(Node *root)
{
    if (root == NULL)
        return;

    // Create two stacks
    stack<Node *> s1, s2;

    // push root to first stack
    s1.push(root);
    Node *node;

    // Run while first stack is not empty
    while (!s1.empty())
    {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    // Print all elements of second stack
    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

// Driver code
int main()
{
    // Let us construct the tree
    // shown in above figure
    Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    postOrderIterative(root);

    return 0;
}

// Iterative Postorder Traversal (Using One Stack)

// We have discussed a simple iterative postorder traversal using two stacks in the previous post. In this post, an approach with only one stack is discussed.

// The idea is to move down to leftmost node using left pointer. While moving down, push root and root’s right child to stack. Once we reach leftmost node, print it if it doesn’t have a right child. If it has a right child, then change root so that the right child is processed before.

// Following is detailed algorithm.

// 1.1 Create an empty stack
// 2.1 Do following while root is not NULL
//     a) Push root's right child and then root to stack.
//     b) Set root as root's left child.
// 2.2 Pop an item from stack and set it as root.
//     a) If the popped item has a right child and the right child
//        is at top of stack, then remove the right child from stack,
//        push the root back and set root as root's right child.
//     b) Else print root's data and set root as NULL.
// 2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
// Let us consider the following tree

// Following are the steps to print postorder traversal of the above tree using one stack.

// 1. Right child of 1 exists.
//    Push 3 to stack. Push 1 to stack. Move to left child.
//         Stack: 3, 1

// 2. Right child of 2 exists.
//    Push 5 to stack. Push 2 to stack. Move to left child.
//         Stack: 3, 1, 5, 2

// 3. Right child of 4 doesn't exist. '
//    Push 4 to stack. Move to left child.
//         Stack: 3, 1, 5, 2, 4

// 4. Current node is NULL.
//    Pop 4 from stack. Right child of 4 doesn't exist.
//    Print 4. Set current node to NULL.
//         Stack: 3, 1, 5, 2

// 5. Current node is NULL.
//     Pop 2 from stack. Since right child of 2 equals stack top element,
//     pop 5 from stack. Now push 2 to stack.
//     Move current node to right child of 2 i.e. 5
//         Stack: 3, 1, 2

// 6. Right child of 5 doesn't exist. Push 5 to stack. Move to left child.
//         Stack: 3, 1, 2, 5

// 7. Current node is NULL. Pop 5 from stack. Right child of 5 doesn't exist.
//    Print 5. Set current node to NULL.
//         Stack: 3, 1, 2

// 8. Current node is NULL. Pop 2 from stack.
//    Right child of 2 is not equal to stack top element.
//    Print 2. Set current node to NULL.
//         Stack: 3, 1

// 9. Current node is NULL. Pop 1 from stack.
//    Since right child of 1 equals stack top element, pop 3 from stack.
//    Now push 1 to stack. Move current node to right child of 1 i.e. 3
//         Stack: 1

// 10. Repeat the same as above steps and Print 6, 7 and 3.
//     Pop 1 and Print 1.

// C program for iterative postorder traversal using one stack
#include <stdio.h>
#include <stdlib.h>

// Maximum stack size
#define MAX_SIZE 100

// A tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Stack type
struct Stack
{
    int size;
    int top;
    struct Node **array;
};

// A utility function to create a new tree node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// A utility function to create a stack of given size
struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node **)malloc(stack->size * sizeof(struct Node *));
    return stack;
}

// BASIC OPERATIONS OF STACK
int isFull(struct Stack *stack)
{
    return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, struct Node *node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

struct Node *pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct Node *peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

// An iterative function to do postorder traversal of a given binary tree
void postOrderIterative(struct Node *root)
{
    // Check for empty tree
    if (root == NULL)
        return;

    struct Stack *stack = createStack(MAX_SIZE);
    do
    {
        // Move to leftmost node
        while (root)
        {
            // Push root's right child and then root to stack.
            if (root->right)
                push(stack, root->right);
            push(stack, root);

            // Set root as root's left child
            root = root->left;
        }

        // Pop an item from stack and set it as root
        root = pop(stack);

        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (root->right && peek(stack) == root->right)
        {
            pop(stack);         // remove right child from stack
            push(stack, root);  // push root back to stack
            root = root->right; // change root so that the right
                                // child is processed next
        }
        else // Else print root's data and set root as NULL
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty(stack));
}

// Driver program to test above functions
int main()
{
    // Let us construct the tree shown in above figure
    struct Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("Post order traversal of binary tree is :\n");
    printf("[");
    postOrderIterative(root);
    printf("]");

    return 0;
}
