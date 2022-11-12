#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int val){
      data=val;
      left=right=NULL;
  }
};

int calcMAX(Node *node){
    
    if(node == NULL)
        return INT_MIN;
    else
        return max(node->data, max(calcMAX(node->left), calcMAX(node->right)));
}

int main() {
	
	Node *root=new Node(20);
	root->left=new Node(70);
	root->right=new Node(90);
	root->left->left=new Node(30);
	root->left->left=new Node(40);
	root->right->right=new Node(70);
	
    cout << "The Max in Tree is : " << calcMAX(root);
}