#include<iostream>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


//DFS post-order
void deleteNode(TreeNode *node){

  if(!node)
    return;

  if(node->left || node->right){
    deleteNode(node->left);
    deleteNode(node->right);
  }
  cout << "deleting: " << node->val << endl;
  free(node);
}

int main(){
  TreeNode *root = new TreeNode(11);
  TreeNode *nine = new TreeNode(9);
  TreeNode *fifteen = new TreeNode(15);
  TreeNode *eight = new TreeNode(8);
  TreeNode *twelve = new TreeNode(12);
  TreeNode *sixteen = new TreeNode(16);
  root->left = nine;
  root->right = fifteen;
  nine->left = eight;
  fifteen->left = twelve;
  fifteen->right = sixteen;
  deleteNode(root);
}

//       11
//    /      \
//   9        15
//  /        /  \
// 8        12  16
