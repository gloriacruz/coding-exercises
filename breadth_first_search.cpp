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

//BFS Level Order
void printTree(TreeNode *node){
  list<TreeNode*> queue;
  queue.push_back(node);

  while(!queue.empty()){
    TreeNode *current = queue.front();
    cout << current->val << ",";
    if(current->left) queue.push_back(current->left);
    if(current->right) queue.push_back(current->right);
    queue.pop_front();
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
