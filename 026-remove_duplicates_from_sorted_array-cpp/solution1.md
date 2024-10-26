# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: **4ms** $$ < 85.04\% $$ 
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: **21.44mb** $$ < 17.68\% $$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    size_t size = nums.size();

    if (size <= 1) return size;

    vector<int> tempVec = {nums[0]};

    size_t count = 1;
    int current = nums[0];

    for (size_t i = 1 ; i < size ; i++) {
      if (nums[i] != current) {
        count++;
        current = nums[i];
        tempVec.push_back(current);
      }
    }

    nums = tempVec;

    return count;
  }
};
```