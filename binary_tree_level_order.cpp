// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
// For example: Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

#include <vector>
#include <list>
#include <iostream>

using namespace std;

class TreeNode{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

//BFS Level Order
vector<vector<int>> printTree(TreeNode* node){
  vector<vector<int>> result;
  vector<int> level;
  int level_width = 1;
  list<TreeNode*> queue;
  queue.push_back(node);

  TreeNode * current;
  while(!queue.empty()){
    current = queue.front();
    level.push_back(current->val);
    if(current->left) queue.push_back(current->left);
    if(current->right) queue.push_back(current->right);
    queue.pop_front();
    level_width--;
    if(level_width == 0){
      result.push_back(level);
      level.clear();
      level_width = queue.size();
    }
  }

  return result;
}

int main(){
  //Build a binary tree
  TreeNode *three = new TreeNode(3);
  TreeNode *nine = new TreeNode(9);
  TreeNode *twenty = new TreeNode(20);
  TreeNode *one = new TreeNode(1);
  TreeNode *two = new TreeNode(2);
  TreeNode *fifthteen = new TreeNode(15);
  TreeNode *seven = new TreeNode(7);
  three->left = nine;
  three->right = twenty;
  // nine->left = one;
  // nine->right = two;
  twenty->left = fifthteen;
  twenty->right = seven;
  vector<vector<int>> result = printTree(three);

  for(auto level : result){
    cout << "[";
    for(int num : level){
      cout << num << ",";
    }
    cout << "]";
  }

  return 1;
}
