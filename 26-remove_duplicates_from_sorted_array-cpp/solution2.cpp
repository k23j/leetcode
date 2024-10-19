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

int main() {
  auto solution = Solution();

  for (auto vec : testList) {
    cout << solution.removeDuplicates(vec) << endl;
  }
}