#include <iostream>
#include <vector>

using namespace std;

const vector<pair<vector<int>,int>> testList = {
  {{1,3,5,6},5},
  {{1,3,5,6},2},
  {{1,3,5,6},7},
};

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

int main() {
  auto solution = Solution();

  for (auto test : testList) {
    cout << solution.searchInsert(test.first,test.second) << endl;
  }
}