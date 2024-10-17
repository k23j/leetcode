#include <iostream>
#include <map>

#include <vector>
#include <string>

using namespace std;

//This vector is used fot test purposes
//Add roman numbers to be converted here
const vector<string> testVec = {
  "III",
  "LVIII",
  "MCMXCIV",
};

// Class used by leetcode to evaluate answers
class Solution {
  private:
    //This map associates the chars of the roman numbers to the values
    const map<char, int> valueMap = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000},
    };

public:

  //Leetcode function
  int romanToInt(string s) {
    int result = 0;

    //Ptr to the first char on the string (c string type)
    const char* ptr = s.c_str();

    //Size of the string
    size_t length = s.length();

    //For each char on the string:
    for (int i = 0; i < length ; i++) {

      //If this is the last char
      //Sum the value as it is on the result
      if (i == length - 1) {
        result += valueMap.at(ptr[i]);

        //In this case loop should skip the next char, as its already summed here
        //So we are advancing one char
        continue;
      }

      //If the next char is of greater value
      //Sum next char value - this char value to the result
      if (valueMap.at(ptr[i]) < valueMap.at(ptr[i+1])) {
        result += valueMap.at(ptr[i+1]) - valueMap.at(ptr[i]);
        i++;
      }
      
      //Normal Case
      //If the next char is lesser 
      //Sum this char value to the result
      else {
        result += valueMap.at(ptr[i]);
      }
    }

    //Return the result
    return result;
  }
};

int main() {
  //Instantiating class needed by leetcode
  auto solution = Solution();

  //Foreach: Print the string and the result
  for (string str : testVec) {
    cout << "The Roman number " << str << " is equivalent to the integer: " << solution.romanToInt(str) << "." << endl;
  }
}