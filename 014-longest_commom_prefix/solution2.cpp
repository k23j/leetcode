#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<vector<string>> caseList = {
  {"dog","racecar","car"},
  {"flower","flow","flight"},
  {""},
  {"a"},
  {"ab", "a"},
  {"reflower","flow","flight"},
};


class Solution {
  private:
    string& getMinStr(vector<string>& strs) {
      size_t index = 0;

      for (size_t i = 1; i < strs.size() ; i++) {
        if (strs[i].length() < strs[index].length()) {
          index = i;
        }
      }

      return strs[index];
    }

  public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.empty()) return "";
      if (strs.size() == 1) return strs[0] ;

      string& minStr = getMinStr(strs);

      for (size_t count = 0 ; count < minStr.length() ; count++) {
        for (const string& str : strs) {
          if (str[count] != minStr[count]) {
            return minStr.substr(0,count);
          }
        }
      }

      return minStr;
    }
};

int main() {
  auto solution = Solution();

  for (vector<string> vec : caseList) {
    cout << solution.longestCommonPrefix(vec) << endl;
  }
}