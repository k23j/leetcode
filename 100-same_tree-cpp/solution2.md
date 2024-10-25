# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: **0ms** $$ < 100\% $$
$$O(n)$$

- Space complexity: **12.06mb** $$ < 81.29\% $$
$$O(n)$$

# Code
```cpp []
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
```