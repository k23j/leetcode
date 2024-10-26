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
    void rec(vector<int*>& vec, const TreeNode* node) {
      if (!node) {
        vec.push_back(nullptr);
        return;
      }

      vec.push_back(new int(node->val));
      rec(vec, node->left);
      rec(vec, node->right);
    }

    vector<int*> levelOrderTraversal(TreeNode* root) {
      if (!root) return {};
      vector<int*> vec;

      rec(vec, root);

      return vec;
    }

  public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if (p == q) return true;
      if (p == nullptr && q == nullptr) return true;
      if (p == nullptr || q == nullptr) return false;

      vector<int*> pT = levelOrderTraversal(p);
      vector<int*> qT = levelOrderTraversal(q);

      if (pT.size() != qT.size()) return false;

      for (size_t i = 0 ; i < pT.size() ; i++) {
        if (pT[i] == nullptr && qT[i] == nullptr) continue;
        if (pT[i] == nullptr || qT[i] == nullptr) return false;
        if (*pT[i] != *qT[i]) return false;
      }

      return true;
    }
};