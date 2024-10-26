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
  const map<const char,const char> map = {
        {')', '('},
        {'}', '{'},
        {']', '['},
      };
  public:
    bool isValid(string s) {
      stack<char> st = {};

      for (size_t i = 0 ; i < s.length() ; i++) {
        //Push
        if (!(map.count(s[i]))) {
          st.push(s[i]);
        }
        //Pop
        else {
          //If closing a block when none is open
          if (st.empty()) return false;
          //Check if last matches
          if (st.top() == map.at(s[i])) {
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