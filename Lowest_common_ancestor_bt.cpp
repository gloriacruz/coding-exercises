// Find the lowest common ancestor of a Binary Tree
//Assumptions: 1. LCA can a be node itself
// 2. All the node values are unique keys
// 3. Both nodes are present in the given tree
// 4. Binary tree is not sorted (not BST)

// OPTION1: Brute force: Transverse all the tree until find the two nodes, store paths
// Find the common node in both paths
// This solution takes space

// OPTION2:
// O(n), no space
//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

      if(!root || !p || !q){
        return NULL;
      }

      if(root == p || root == q){
        return root;
      }

      TreeNode *left = lowestCommonAncestor(root->left, p, q);
      TreeNode *right = lowestCommonAncestor(root->right, p, q);

      if(left && right) return root;

      if(!left && !right ) return NULL;

      return left ? left : right;
    }
};

//Driver code
int main() {
  //Build a binary tree
  TreeNode *three = new TreeNode(3);
  TreeNode *six = new TreeNode(6);
  TreeNode *eight = new TreeNode(8);
  TreeNode *two = new TreeNode(2);
  TreeNode *eleven = new TreeNode(11);
  TreeNode *nine = new TreeNode(9);
  TreeNode *five = new TreeNode(5);
  TreeNode *thirdteen = new TreeNode(13);
  TreeNode *seventeen = new TreeNode(17);

  three->left = six;
  three->right = eight;
  six->left = two;
  six->right = eleven;
  eleven->left = nine;
  eleven->right = five;
  eight->right = thirdteen;
  thirdteen->left = seventeen;

  Solution *sol = new Solution;
  TreeNode *LCA = (*sol).lowestCommonAncestor(three, two, five);


  cout<<"Lowest Common Ancestor is: " << LCA->val;
  return 0;
}
