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

//Binary search solution
class Solution {
public:
  int mySqrt(int x) {
    if (x <= 1) return x;

    int left = 1;
    //This is the square root of the max int alowed in cpp
    //thus the highest result we can endup with
    int right = 46340;

    while (left <= right) {
      if (left * left == x) return left;
      if (right * right == x) return right;

      //calc the mid loc
      //if a = 10 and b=20
      //mid = 10 + (20-10) / 2
      //mid = 10 + 10 / 2
      //mid = 10 + 5
      //mid = 15;
      int mid = left + (right - left) / 2;

      int result = mid * mid;

      if (result == x) return mid;

      //If the result is in the left side
      if (x < result) {
        //limiting to left side
        //now from a = 10
        //to b = 14
        //15 already tested (mid)
        right = mid - 1;
      } else {
        //limiting to right side
        //now from a = 16
        //15 already tested (mid)
        //to b = 20
        left = mid + 1;
      }
    }

    return right;
  }
};
```