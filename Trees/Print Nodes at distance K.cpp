#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right;
  
  Node(int val){
      data = val;
      left = right = NULL;
  }
};

void printKDistance(Node *root,int k){
    if(root==NULL)
        return;
    
    if(k==0){
        cout<<root->data<<" ";
        
    }
    else{
    printKDistance(root->left,k-1);
    printKDistance(root->right,k-1);
    }
}


int main() {
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left>left=new Node(4);
	root->left>right=new Node(5);
	
	int k = 2;
	
	printKDistance(root,k);
	
	return 0;

}