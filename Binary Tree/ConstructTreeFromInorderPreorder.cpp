//{ Driver Code Starts
//

#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

class Solution{
    public:
    int findPosition(int in[], int startInIndex, int endInIndex, int element)
    {
        for(int i = startInIndex; i <= endInIndex; i++)
            if(in[i] == element)
                return i;
        return -1;
    }
    Node* solve(int in[], int pre[], int &preOrderIndex, int startInIndex, int endInIndex, int n)
    {
		//Base Condition
         if(preOrderIndex >= n || startInIndex > endInIndex)
            return NULL;
		
		//decide root node from preorder Node-Left-Right(NLR)
        int element = pre[preOrderIndex++];
        Node* root  = new Node(element); 
		//find Positon for elemnt in inorder
        int position  = findPosition(in, startInIndex, endInIndex, element);

		//we are creating first left subtree coz NLR
        root -> left = solve(in, pre, preOrderIndex, startInIndex, position - 1, n);
        root -> right = solve(in, pre, preOrderIndex, position + 1, endInIndex, n);
        return root;
    }
    
    Node* buildTree(int in[], int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        int startInIndex = 0;
        int endInIndex = n - 1;
        return solve(in, pre, preOrderIndex, startInIndex, endInIndex, n);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends