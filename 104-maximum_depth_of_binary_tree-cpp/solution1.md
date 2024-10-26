# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
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
```