//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}






// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void leftNodes(Node* root, vector<int> &result){

        //BASE conditions
        if(root == NULL)    return;

        if(root->left== NULL && root->right== NULL)
        {
            return;
        }

        //main body for recursion
        //store data in result
        result.push_back(root->data);

        //check if root.left exist or no
        if(root->left)
            leftNodes(root->left, result);
        
        else
            leftNodes(root->right, result);
        
    }

    void leafNodes(Node* root, vector<int> &result){
        if(root == NULL)
            return;
        
        if(root->left== NULL && root->right== NULL)
            return result.push_back(root->data);

        leafNodes(root->left, result);
        leafNodes(root->right, result);


    }

    void reverseRightNodes(Node* root, vector<int> &result){
        //Base Condition
        if(root == NULL)
            return;
        
        if(root->left== NULL && root->right== NULL)
        {
            return;
        }

        // main first go to right side of tree
        //check if ri8 exist if not that go to left node 
        if(root->right)
            reverseRightNodes(root->right, result);
        else
            reverseRightNodes(root->left, result);
        
        result.push_back(root->data);

    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector <int> result;
        if(root== NULL)
            return result;
        result.push_back(root->data);
        //to read all left nodes of tree excluding leaf nodes
        //left side
        leftNodes(root->left, result);
        //to read only leaf odes of tree
        leafNodes(root->left, result);
        leafNodes(root->right, result);

        // to read data from right  nodes of tree in reverse order , excluding leaf nodes
        reverseRightNodes(root->right, result);

    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends