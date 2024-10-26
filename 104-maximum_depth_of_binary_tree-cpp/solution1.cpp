
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
    void rec(int& max, int current, const TreeNode* node) {
      if (!node) return;
      if (current > max) max = current;
      rec(max,current+1,node->left);
      rec(max,current+1,node->right);
    }
public:
    int maxDepth(TreeNode* root) {
      if (!root) return 0;

      int depth = 1;
      rec(depth, depth, root);

      return depth;
    }
};