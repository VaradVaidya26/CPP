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
void print(std::vector <Node *> const &a) {
   cout << "The path is: : ";

   for(int i=0; i < a.size(); i++)
   cout << a.at(i)->data << ' ';
   return;
}

bool findPath(Node *root, vector<Node *> &p, int n){
    if(root==NULL)
        return false;
        
    p.push_back(root);
    
    if(root->data==n)
        return true;
    
    if(findPath(root->left,p,n)||findPath(root->right,p,n))
    return true;
    
    p.pop_back();
    return false;
}

Node *lca(Node *root, int val1, int val2)
{
    vector <Node *> path1, path2;
    
    if(findPath(root,path1,val1) == false || findPath(root,path2,val2) == false)
        return NULL;
    
    cout << "For node 1: ";
    print(path1);
    cout << "\nFor node 2: ";
    print(path2);
    
    for(int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
        if(path1[i+1] != path2[i+1])
            return path1[i];
    return NULL;
}

int main() {
	
	Node *root=new Node(70);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(50);
	root->left->right=new Node(10);
	root->left->left->left=new Node(60);
	root->left->left->right=new Node(40);
	root->left->left->left->left=new Node(90);
	root->left->left->right->right=new Node(110);
	root->left->right->right=new Node(80);
	root->left->right->right->right=new Node(100);
	

	Node *result = lca(root,90,110);
	cout << "\nLowest Common Ancestor: "<< result->data;
}