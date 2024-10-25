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
    void rec(vector<int>& vec, const TreeNode* node) {
      if (node->left) rec(vec, node->left);
      vec.push_back(node->val);
      if (node->right) rec(vec,node->right);
    }

  public:
    vector<int> inorderTraversal(TreeNode* root) {
      if (!root) return {};
      vector<int> vec;

      rec(vec, root);

      return vec;
    }
};