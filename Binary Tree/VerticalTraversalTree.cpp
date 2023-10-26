//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include<map>

using namespace std;

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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> result;
        //map order is map<hd, map<lvl, vector<int>>>
        map<int, map<int, vector<int>>> map;
        
        //base Condition
        if(root== NULL)
            return result;
            
        // push root to queue and level, horizontal Distance
        queue<pair<Node*, pair<int, int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        //here in above level=0, horizontal Distance=0
        
        while(!q.empty()){
            //take that front element of queue as front outside and 
            //later pop element from queue 
            pair<Node*,pair<int, int>> tempFront= q.front();
            q.pop();

            //seperate node from tempFront
            Node* front= tempFront.first;

            int hd= tempFront.second.first;
            int lvl= tempFront.second.second;

            //Main Operation of Vertical Traversal
            //simple map each hd with different level all data in vector
            map[hd][lvl].push_back(front->data);

            //if left exist------traverse for all left subtree
            if(front->left)
                q.push(make_pair(front->left, make_pair(hd-1, lvl+1)));
            if(front->right)
                q.push(make_pair(front->right, make_pair(hd+1, lvl+1)));
            

        }
        // traverse map ....coz vector is our solution for vertical traversal
        for(auto i:map){
            for(auto j: i.second){
                for(auto k: j.second){
                    result.push_back(k);
                }
            }
        }
        return result;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends