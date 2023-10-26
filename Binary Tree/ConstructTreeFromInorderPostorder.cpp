//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/



int findPosition(int inorder[], int element, int inorderEndIndex) {
    for (int i = inorderEndIndex; i >= 0; i--) {
        if (inorder[i] == element) {
            return i;
        }
    }
    return -1;
}

Node* treeConstructFrominorderPostOrder(int inorder[], int postorder[], int inorderStartIndex, int inorderEndIndex, int &postorderIndex) {
    //Base Condition
    if (postorderIndex < 0 || inorderStartIndex > inorderEndIndex) {
        return NULL;
    }
    //decide root node from preorder Node-Left-Right(NLR)
    //take element from psotorder elemnt for root node later create a node from it
    int element = postorder[postorderIndex--];
    Node* root = new Node(element);

    //find position of element from postORDER in Inorder array
    int position = findPosition(inorder, element, inorderEndIndex);

    //we are creating first left subtree coz LRN
    //create first right subtree later create left subtree ...we are going in opposite
    root->right = treeConstructFrominorderPostOrder(inorder, postorder, position + 1, inorderEndIndex, postorderIndex);
    root->left = treeConstructFrominorderPostOrder(inorder, postorder, inorderStartIndex, position - 1, postorderIndex);

    return root;
}

Node* buildTree(int inorder[], int postorder[], int n) {
    int inorderStartIndex = 0;
    int inorderEndIndex = n - 1;
    int postorderIndex = n - 1;
    return treeConstructFrominorderPostOrder(inorder, postorder, inorderStartIndex, inorderEndIndex, postorderIndex);
}
