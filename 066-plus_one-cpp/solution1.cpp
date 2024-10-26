#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> testList = {
  {1,2,3},
  {4,3,2,1},
  {9},
};

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

int main() {
  auto solution = Solution();

  for (auto test : testList) {
    auto result = solution.plusOne(test);

    for (auto x : result) {
      cout << x << ",";
    }

    cout << endl;
  }
}