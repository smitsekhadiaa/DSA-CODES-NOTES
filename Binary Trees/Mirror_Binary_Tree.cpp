// Create a mirror tree from the given binary tree
// Given a binary tree, the task is to create a new binary tree which is a mirror image of the given binary tree.

// Examples:

// Input:
//         5
//        / \
//       3   6
//      / \
//     2   4
// Output:
// Inorder of original tree: 2 3 4 5 6
// Inorder of mirror tree: 6 5 4 3 2
// Mirror tree will be:
//   5
//  / \
// 6   3
//    / \
//   4   2

// Input:
//         2
//        / \
//       1   8
//      /     \
//     12      9
// Output:
// Inorder of original tree: 12 1 2 8 9
// Inorder of mirror tree: 9 8 2 1 12

// METHOD 1

// Approach: Write a recursive function that will take two nodes as the argument, one of the original tree and the other of the newly created tree. Now, for every passed node of the original tree, create a corresponding node in the mirror tree and then recursively call the same method for the child nodes but passing the left child of the original tree node with the right child of the mirror tree node and the right child of the original tree node with the left child of the mirror tree node.

// CODE FOR METHOD1:

// C++ implementation of the approach
// #include <iostream>
// using namespace std;

// // A binary tree node has data, pointer to
// // left child and a pointer to right child
// typedef struct treenode {
// 	int val;
// 	struct treenode* left;
// 	struct treenode* right;
// } node;

// // Helper function that allocates a new node with the
// // given data and NULL left and right pointers
// node* createNode(int val)
// {
// 	node* newNode = (node*)malloc(sizeof(node));
// 	newNode->val = val;
// 	newNode->left = NULL;
// 	newNode->right = NULL;
// 	return newNode;
// }

// // Helper function to print Inorder traversal
// void inorder(node* root)
// {
// 	if (root == NULL)
// 		return;
// 	inorder(root->left);
// 	cout <<" "<< root->val;
// 	inorder(root->right);
// }

// // mirrorify function takes two trees,
// // original tree and a mirror tree
// // It recurses on both the trees,
// // but when original tree recurses on left,
// // mirror tree recurses on right and
// // vice-versa
// void mirrorify(node* root, node** mirror)
// {
// 	if (root == NULL) {
// 		mirror = NULL;
// 		return;
// 	}

// 	// Create new mirror node from original tree node
// 	*mirror = createNode(root->val);
// 	mirrorify(root->left, &((*mirror)->right));
// 	mirrorify(root->right, &((*mirror)->left));
// }

// // Driver code
// int main()
// {

// 	node* tree = createNode(5);
// 	tree->left = createNode(3);
// 	tree->right = createNode(6);
// 	tree->left->left = createNode(2);
// 	tree->left->right = createNode(4);

// 	// Print inorder traversal of the input tree
// 	cout <<"Inorder of original tree: ";
// 	inorder(tree);
// 	node* mirror = NULL;
// 	mirrorify(tree, &mirror);

// 	// Print inorder traversal of the mirror tree
// 	cout <<"\nInorder of mirror tree: ";
// 	inorder(mirror);

// 	return 0;
// }

// METHOD 2:
// In order to change the original tree in its mirror tree, then we simply swap the left and right link of each node. If the node is leaf node then do nothing.

// CODE FOR METHOD 2: better method

#include <iostream>
using namespace std;

typedef struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
} node;

// Helper function that
// allocates a new node with the
// given data and NULL left and right pointers
node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to print the inrder traversal
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Function to convert to mirror tree
treenode *mirrorTree(node *root)
{
    // Base Case
    if (root == NULL)
        return root;
    node *t = root->left;
    root->left = root->right;
    root->right = t;

    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);

    return root;
}

// Driver Code
int main()
{

    node *tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);
    printf("Inorder of original tree: ");
    inorder(tree);

    // Function call
    mirrorTree(tree);

    printf("\nInorder of Mirror tree: ");
    inorder(tree);
    return 0;
}
