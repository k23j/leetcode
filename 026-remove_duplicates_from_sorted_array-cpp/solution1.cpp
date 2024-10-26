#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> testList = {
  {1,1,2},
  {0,0,1,1,1,2,2,3,3,4},
};

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

int main() {
  auto solution = Solution();

  for (auto vec : testList) {
    cout << solution.removeDuplicates(vec) << endl;
  }
}