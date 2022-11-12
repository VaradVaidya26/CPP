#include <bits/stdc++.h>
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

int max_height(struct Node* node)
{
    //change to -1 
    if (node == NULL)
        return 0;
    else {
        /* calculate the Height of each (Left/ right) subtree */
        int lHeight = max_height(node->left);
        int rHeight = max_height(node->right);
 
        /* use the larger value */
        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	
    cout << "The height of tree is :" <<max_height(root) << endl;

}