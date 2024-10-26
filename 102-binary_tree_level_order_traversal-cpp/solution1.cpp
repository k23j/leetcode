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
    void rec(const int pos, vector<vector<int>>& vec, const TreeNode* node) {
      if (!node) return;

      if (vec.size() < pos + 1) vec.push_back({});

      vec[pos].push_back(node->val);

      rec(pos+1,vec,node->left);
      rec(pos+1,vec,node->right);
    }

  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      if (!root) return {};

      vector<vector<int>> result = {};

      rec(0,result,root);

      return result;
    }
};