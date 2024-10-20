# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: **0ms** && < 00\% &&
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: **10.56mb** && < 91.7\% &&
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []

class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      //size_t size = nums.size();
      size_t count = 0;
      size_t i = 0;

      while (i < (nums.size() - count)) {
        int currentVal = nums[i];
        if (currentVal == val) {
          nums[i] = nums[(nums.size() - 1) - count];
          count++;
        } else {
          i++;
        }
      }

      return i;
    }
};

```