 //DFS Preorder: print output to screen
  //       3
  //     /    \
  //    6      8
  //   / \    /  \
  //  2  11  17  13
  //Output: 3,6,2,11,8,17,13

#include <iostream>

using namespace std;

class TreeNode{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

//DFS Preorder
void printTree(TreeNode *node){
  if(node == NULL)
    return;
  cout << node->val << ",";
  printTree(node->left);
  printTree(node->right);
}

int main(){
  //Build a binary tree
  TreeNode *three = new TreeNode(3);
  TreeNode *six = new TreeNode(6);
  TreeNode *eight = new TreeNode(8);
  TreeNode *two = new TreeNode(2);
  TreeNode *eleven = new TreeNode(11);
  TreeNode *thirdteen = new TreeNode(13);
  TreeNode *seventeen = new TreeNode(17);

  three->left = six;
  three->right = eight;
  six->left = two;
  six->right = eleven;
  eight->left = seventeen;
  eight->right = thirdteen;
  printTree(three);
  return 1;
}
