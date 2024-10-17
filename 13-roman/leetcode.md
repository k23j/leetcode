# Intuition
At sight I think of using a map to associate the roman chars to integers.

# Approach
1. Created a const map to store associate the values
2. Itarate the c type string
3. If the char is the last, or if preceeds a char with lesser value, just sum it's value to the result
4. If the char preeces a char of greater value, sum the difference
5. Return the result after iterating


<!-- TODO: Calc complexity -->
# Complexity
- Time complexity: Beats 100%
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: Beats 78.44%
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
#include <map>

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

class Solution {
public:
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

        //Continue the loop preventing the other scenarios to take effect
        continue;
      }

      //If the next char is of greater value
      //Sum next char value - this char value to the result
      if (valueMap.at(ptr[i]) < valueMap.at(ptr[i+1])) {
        result += valueMap.at(ptr[i+1]) - valueMap.at(ptr[i]);

        //In this case loop should skip the next char, as its already summed here
        //So we are advancing one char
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
```