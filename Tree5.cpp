/*Inorder Preorder Postorder*/
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value):data(value),left(nullptr),right(nullptr){}
};
Node* newNode(int data,Node* left=nullptr,Node* right=nullptr){
    Node* node=new Node(data);
    node->data=data;
    node->left=left;
    node->right=right;
}
void inorderTraversal(Node* root){
    if(root==nullptr)
        {
            return;
        }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void preorderTraversal(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node* root)
{
    if(root==nullptr){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    inorderTraversal(root);
    cout<<endl;
    preorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    return 0;
}

