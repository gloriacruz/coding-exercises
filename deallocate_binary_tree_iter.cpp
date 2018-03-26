//INCOMPLETE!!

#include<iostream>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


//DFS non-recursive
void deleteTree(TreeNode *root){
  Treenode *node = root;
  Treenode *parentNode = root;

  do{
    while(node->left || node->right){
      parentNode = node;
      if(node->left)
        node = node->left;
      else
        node = node->right;
    }
    cout << "deleting: " << node->val << endl;
    free(node);
  }while(parentNode != root);
  cout << "deleting: " << root->val << endl;
  free(root);
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
  deleteTree(root);
}

//       11
//    /      \
//   9        15
//  /        /  \
// 8        12  16
