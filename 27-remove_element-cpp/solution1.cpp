#include <iostream>
#include <vector>

using namespace std;

const vector<pair<vector<int>,int>> testList = {
  {{3,2,2,3}, 3},
  {{0,1,2,2,3,0,4,2}, 2},
};

class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      size_t count = 0;
      size_t i = 0;

      while (i < (nums.size() - count)) {
        int currentVal = nums[i];
        if (currentVal == val) {
          nums[i] = nums[(nums.size() - 1) - count];
          nums[(nums.size() - 1) - count] = currentVal;
          count++;
        } else {
          i++;
        }
      }

      return i;
    }
};

int main() {
  auto solution = Solution();

  for (auto test : testList) {
    cout << solution.removeElement(test.first,test.second) << endl;
  }
}