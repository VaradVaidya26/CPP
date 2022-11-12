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

int max_level_visited = 0;


void print_left_view(Node *node, int curr_level)
{
    if (node == NULL)  
        return;
        
    if(max_level_visited < curr_level)
    {
        cout << node->data << " ";
        max_level_visited = curr_level;
    }
    
    print_left_view(node->left, curr_level+1);
    print_left_view(node->right, curr_level+1);
    
}

void helper_left_view(Node *root){
    print_left_view(root, 1);
    
}

int main() {
	
	Node *root=new Node(20);
	root->left=new Node(70);
	root->right=new Node(90);
	root->left->left=new Node(30);
	root->left->left=new Node(40);
	root->right->right=new Node(70);
	
    helper_left_view(root);
}