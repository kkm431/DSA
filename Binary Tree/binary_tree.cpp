#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data= data;
        this->left= NULL;
        this->right= NULL;

    }
};


//Build node and link it accordingly
Node* buildTree(){

    int d;
    cout<<"Enter root data:";
    cin>>d;

    Node* root= new Node(d);

    if(d== -1)
        return NULL;
    
    cout<<endl<<"Enter left node of "<<d<< ":";
    root->left= buildTree();

    cout<<endl<<"Enter right node of "<<d<< ":";
    root->right= buildTree();

    return root;

}

//levelOrderTraversal
void  levelOrderTraversal(Node* root){
    //If tree is empty()
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr= q.front();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->left != NULL)  
            q.push(curr->left);
        
        if(curr->right != NULL)
            q.push(curr->right);
        
    }


}

//preOrderTraversal
void preOrderTraversal(Node* root){
    if(root == NULL)
        return;
    
    cout<<root->data <<" ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//postOrderTraversal
void postOrderTraversal(Node* root){
    if(root== NULL)
        return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout<<root->data<<" ";
}

//inOrderTraversal
void inOrderTraversal(Node* root){
    if(root== NULL)
        return;
    
    inOrderTraversal(root->left);

    cout<<root->data<<" ";

    inOrderTraversal(root->right);
}


//Count Leaf Node
int countLeafNode(Node* root){
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right== NULL){
        return 1;
    }

    int leftCount= countLeafNode(root->left);
    int rightCount= countLeafNode(root->right);

    return leftCount+ rightCount;

}

//Print Leaf Nodes
void leafNodeInTree(Node* root){
    if(root== NULL)
        return;
    
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<endl;
        return;
    }

    //traverse for left nodes
    leafNodeInTree(root->left);

    //traverse for right nodes
    leafNodeInTree(root->right);

    return;
}

int main()
{
    Node* root =buildTree();
    cout<<"Level Order Traversal"<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"PreOrder Traversal"<<endl;
    preOrderTraversal(root);

    cout<<endl<<"PostOrder Traversal"<<endl;
    postOrderTraversal(root);

    cout<<endl<<"inOrder Traversal"<<endl;

    inOrderTraversal(root);
    
    cout<<endl<<"Count of Leaf Nodes:"<<countLeafNode(root)<<endl;
    
    leafNodeInTree(root);

    cout<<endl;
    return 0;

}
