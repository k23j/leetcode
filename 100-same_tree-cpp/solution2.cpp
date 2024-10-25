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

    bool rec(TreeNode* nodeA, TreeNode* nodeB) {
      if (!nodeA && !nodeB) return true;
      if (nodeA || nodeB) return false;

      bool innerResult = rec(nodeA->left,nodeB->left) && rec(nodeA->right,nodeB->right);

      if (!innerResult) return false;

      return (nodeA->val == nodeB->val);
    }

  public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if (p == nullptr && q == nullptr) return true;
      if (p == nullptr || q == nullptr) return false;

      return rec(p,q);
    }
};