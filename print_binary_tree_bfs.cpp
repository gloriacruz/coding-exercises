// Your last Python code is saved below:
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//get height
int getHeight(TreeNode* root){
  if(!root) return 0;

  int leftHeight = getHeight(root->left);
  int rightHeight = getHeight(root->right);

  if(leftHeight > rightHeight)
    return leftHeight + 1;
  else
    return rightHeight + 1;
}

//fill matrix with "" using formula
void fillRow(vector<vector<string>> &printedTree, TreeNode* node, int rowNum, int colStart, int colEnd){
  printedTree[rowNum][(colEnd+colStart)/2] = to_string(node->val);
  if(node->left == NULL && node->right == NULL)
    return;
  if(node->left) fillRow(printedTree, node->left, rowNum+1, colStart, (colEnd+colStart)/2-1);
  if(node->right) fillRow(printedTree, node->right, rowNum+1, (colEnd+colStart)/2+1, colEnd);
}

//recursively place values
vector<vector<string>> printTree(TreeNode* root) {
  int treeHeight = getHeight(root);
  vector<string> initializer(pow(2,treeHeight)-1,"''");
  vector<vector<string>> printedTree(treeHeight,initializer);
  fillRow(printedTree, root, 0, 0, (pow(2,treeHeight)-1)-1);
  return printedTree;
}

void printMatrix(vector<vector<string>> printedTree){
  for(auto row : printedTree){
    for(auto val : row){
      cout << val << "|";
    }
    cout << endl;
  }
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
  vector<vector<string>> printedTree = printTree(root);
  printMatrix(printedTree);
}

//       11
//    /      \
//   9        15
//  /        /  \
// 8        12  16