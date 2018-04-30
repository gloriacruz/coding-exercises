#include <iostream>
#include <list>

using namespace std;

class TreeNode{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};
  //        3
  //     /    \
  //    6      8
  //   / \    /  \
  //  2  11  17  13
  // Output: 3,6,8,2,11,17,13

int getHeight(TreeNode *node){
  int height = 0;

  if(node){
    height++;
    int left = getHeight(node->left);
    int right = getHeight(node->right);

    if(left > right) {
      height += left;
    }else{
      height += right;
    }
  }
  return height;
}

void printLevel(TreeNode *root, int level){
  if(!root) return;
  if(level == 1){
    cout << root->val << ",";
  }else if(level > 1){
    printLevel(root->left, level-1);
    printLevel(root->right, level-1);
  }
}

//BFS Level Order II
void printTree(TreeNode *node){
  int height = getHeight(node);
  for(int level = 1; level <= height; level++){
    printLevel(node, level);
  }
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
