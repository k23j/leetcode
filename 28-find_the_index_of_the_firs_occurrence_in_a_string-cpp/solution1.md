# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: **0ms** && < 100\% $$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: **7.62mb** && < 96.36\% $$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []

class Solution {
  public:
    int strStr(string haystack, string needle) {
      if (haystack.length() < needle.length()) return -1;

      char first = needle[0];

      int occurrenceId = 0;

      while (occurrenceId <= haystack.length() - needle.length()) {
        if (haystack[occurrenceId] == first) {
          bool match = true;
          for (size_t i = 1 ; i < needle.length() ; i++) {
            if (haystack[occurrenceId + i] != needle[i]) {
              match = false;
              break;
            }
          }
          if (match) return occurrenceId;
        }

        occurrenceId++;
      }

      return -1;
    }
};

```