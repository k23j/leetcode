#include <iostream>
#include <vector>

using namespace std;

const vector<vector<string>> caseList = {
  {"flower","flow","flight"},
};

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      size_t minStrLength = shortestStringLength(strs);
      size_t vecSize = strs.size();

      char result[minStrLength];

      //Set the first char of the result to be equal to the first char of the first str
      // *result[0] = strs[0][0];

      size_t index = 0;

      bool failed = false;

      //For each char on the result
      for (index = 0 ; index < minStrLength - 1 ; index++) {
        result[index] = strs[0][index];

        //Check if the currespondent index checks
        for (size_t i = 1 ; i < vecSize ; i++) {
          if (strs[i].at(index) != result[index]) {
            failed = true;
            break;
          }
        }

        if (failed) {
          result[index] = '\0';
          break;
        }
      }

      if (!failed) {
        result[index + 1] = '\0';
      }

      return string{*result};
    }

  private:
    size_t shortestStringLength(vector<string>& strs) {
      size_t length = strs[0].length();

      for (size_t i = 1 ; i < strs.size() ; i++) {
        size_t strLength = strs[i].length();
        if (strLength < length) {
          length = strLength;
        }
      }

      return length;
    }
};

int main() {
  auto solution = Solution();

  for (vector<string> vec : caseList) {
    cout << solution.longestCommonPrefix(vec) << endl;
  }
}