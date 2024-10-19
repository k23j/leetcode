# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: **0ms** $$ < 100\% $$ 
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: **21.31mb** $$ < 56.95\% $$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    size_t size = nums.size();

    if (size <= 1) return size;

    size_t count = 1;
    int current = nums[0];

    for (size_t i = 1 ; i < size ; i++) {
      if (nums[i] != current) {
        current = nums[i];
        // No need to offset to index as the increment not happened yet
        nums[count] = current; 
        count++;
      }
    }

    return count;
  }
};
```