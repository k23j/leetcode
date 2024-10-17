#include <iostream>
#include <map>

#include <vector>
#include <string>

using namespace std;

const map<char, int> valueMap = 
{
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000},
};

const vector<string> testVec = {
  "III",
  "LVIII",
  "MCMXCIV",
};

class Solution {
public:
    int romanToInt(string s) {
      int result = 0;
      const char* ptr = s.c_str();
      size_t length = s.length();

      for (int i = 0; i < length ; i++) {
        if (ptr[i+1] == '\0') {
          result += valueMap.at(ptr[i]);
          continue;
        }

        if (valueMap.at(ptr[i]) < valueMap.at(ptr[i+1])) {
          result += valueMap.at(ptr[i+1]) - valueMap.at(ptr[i]);
          i++;
          continue;
        } 
        
        else {
          result += valueMap.at(ptr[i]);
          continue;
        }
      }

      return result;
    }
};

int main() {
  auto solution = Solution();

  for (string str : testVec) {
    cout << "The Roman number " << str << " is equivalent to the integer: " << solution.romanToInt(str) << "." << endl;
  }
}