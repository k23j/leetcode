#include <iostream>
#include <vector>
#include <map>

using namespace std;

const vector<int> testList = {
    10, 2, 121, 2147483647, 16384, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100,
    121, 256, 1024, 2048, 4096, 8192, 12345, 54321, 99999, 500000,
};

//Binary search solution
class Solution {
public:
  int mySqrt(int x) {
    if (x <= 1) return x;

    int left = 1;
    //This is the square root of the max int alowed in cpp
    //thus the highest result we can endup with
    int right = 46340;
    int mid, result;

    while (left <= right) {
      if (left * left == x) return left;
      if (right * right == x) return right;

      //calc the mid loc
      //if a = 10 and b=20
      //mid = 10 + (20-10) / 2
      //mid = 10 + 10 / 2
      //mid = 10 + 5
      //mid = 15;
      mid = left + (right - left) / 2;

      result = mid * mid;

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

int main()
{
  auto solution = Solution();

  for (int test : testList)
  {
    cout << "The sqrt of " << test << " is: " << solution.mySqrt(test) << "." << endl;
  }
}