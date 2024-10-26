#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

const vector<string> testCaseVec = {
  "()",
  "()[]{}",
  "(]",
  "([])",
  "([)]",
  "]",
};

class Solution {
  private:
  const map<const char,const char> closingMap = {
        {')', '('},
        {'}', '{'},
        {']', '['},
      };
  public:
    bool isValid(string s) {
      stack<char> st = {};

      for (size_t i = 0 ; i < s.length() ; i++) {
        //Push
        //If not included in the close map
        //Opening a block
        if (!(closingMap.count(s[i]))) {
          st.push(s[i]);
        }
        //Pop
        //Closing block
        else {
          //If closing a block when none is open
          if (st.empty()) return false;
          //Check if last matches
          if (st.top() == closingMap.at(s[i])) {
            st.pop();
          } else {
            return false;
          }
        }
      }

      return (st.empty());
    }
};

int main() {
  auto solution = Solution();

  for (const string& test : testCaseVec) {
    cout << "The string: " << test << " is " << (solution.isValid(test) ? "valid." : "invalid.") << endl;
  }
}