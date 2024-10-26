# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: **0ms** $$ < 100\% $$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: **12.36mb** $$ < 61.04\% $$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    for (size_t i = 0 ; i < nums.size() ; i++) {
      if (target <= nums[i]) {
        return i;
      }
    }

    return nums.size();
  }
};
```