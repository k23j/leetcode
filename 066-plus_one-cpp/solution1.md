# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: **0ms** $$ < 100\% $$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: **10.54mb** $$ < 47.05\% $$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int i = digits.size() - 1;

      while (i >= 0 && digits[i] == 9) {
        digits[i] = 0;
        i--;
      }

      if (i >= 0) {
        digits[i] += 1;
      } else {
        digits.insert(digits.cbegin(),1);
      }

      return digits;
    }
};

```