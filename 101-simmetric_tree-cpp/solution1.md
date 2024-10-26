# Intuition

My first thought was to use the same logic as in problem 100 (same_tree), but in a symmetric way.

# Approach
Define a recursive function that checks equality and if so, propragate.
1. The function first checks if the 2 nodes are nullptr, thus equal, return true ending the propragation as being null indicates this is a leaf node.
2. Then checks if one of the nodes is null while the other is not, indicating a mismatch, returning false, as every node should find its simmetric counterpart.
3. Now we know both nodes are valid, so we check for inequality, returng a false only in this case, as if its valid we want to propragate.
4. Now we propragate, returning with a call to this function for each case, one for left comparing to right, and right comparing to left (symmetric), and ensuring to return true only if both cases are valid, thus using the && operator.

# Complexity
- Time complexity: **0ms** $$ < 100\% $$
The time complexity is $$O(n)$$.

- Space complexity: **17.74mb** $$ < 10.69\% $$
This solutions ended up being too space demanding, but the idea here was to reuse the code from the last problem, and solve this problem fast, I tend to go back here and try a solution that uses less memory.

![LeetCode Result](solution1_result.png)

# Code
```cpp []
class Solution {
  private:

    bool rec(const TreeNode* nodeA, const TreeNode* nodeB) {
      if (!nodeA && !nodeB) return true;
      if ((nodeA && !nodeB) || (!nodeA && nodeB)) return false;

      if (nodeA->val != nodeB->val) return false;

      return rec(nodeA->left,nodeB->right) && rec(nodeA->right,nodeB->left);
    }

  public:

    bool isSymmetric(TreeNode* root) {
      return rec(root->left,root->right);
    }
};
```