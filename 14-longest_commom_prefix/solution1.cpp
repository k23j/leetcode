#include <iostream>
#include <vector>

using namespace std;

const vector<vector<string>> caseList = {
  {"flower","flow","flight"},
  {"dog","racecar","car"},
  {""},
  {"a"},
  {"ab", "a"},
};

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      //If the vector is empty return ""
      if (strs.empty()) return "";

      //If theres only on string returns it
      if (strs.size() == 1) return strs[0];

      size_t minStrLength = shortestStringLength(strs);

      //If theres an empty string return ""
      if (minStrLength == 0) return "";

      size_t vecSize = strs.size();

      char result[minStrLength + 1];

      size_t index = 0;

      bool failed = false;

      //For each char on the result
      for (index = 0 ; index < minStrLength ; index++) {
        result[index] = strs[0][index];

        //Check every string if the char matchs with the first (except the first str)
        for (size_t i = 1 ; i < vecSize ; i++) {
          //Check if the currespondent index checks
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
        result[index] = '\0';
      }

      return result;
    }

  private:
    size_t shortestStringLength(vector<string>& strs) {
      //Set the first string length as the base length
      size_t length = strs[0].length();

      //For the others string compare if their size is smaller
      for (size_t i = 1 ; i < strs.size() ; i++) {
        size_t strLength = strs[i].length();

        if (strLength == 0) return 0; //If the size is 0 (minimum possible size) return 0

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