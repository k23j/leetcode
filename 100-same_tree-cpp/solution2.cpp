#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  private:

    bool rec(const TreeNode* nodeA, const TreeNode* nodeB) {
      if (!nodeA && !nodeB) return true;
      if ((nodeA && !nodeB) || (!nodeA && nodeB)) return false;

      if (nodeA->val != nodeB->val) return false;

      return rec(nodeA->left,nodeB->left) && rec(nodeA->right,nodeB->right);
    }

  public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
      return rec(p,q);
    }
};