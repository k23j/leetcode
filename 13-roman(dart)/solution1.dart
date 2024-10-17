import 'dart:core';

const List<String> testList = ["III", "LVIII", "MCMXCIV"];

class Solution {
  final Map<String, int> valueMap = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
  };

  int romanToInt(String s) {
    int result = 0;

    for (int index = 0; index < s.length; index++) {
      int letterValue = valueMap[s[index]]!;

      //Sum last letter
      if (index == s.length - 1) {
        result += letterValue;
        break;
      }

      int nextLetterValue = valueMap[s[index + 1]]!;

      //Case this letter is lesser than the next
      //Sum the difference
      if (letterValue < nextLetterValue) {
        result += nextLetterValue - letterValue;
        index++;
      }
      //Else default behavior
      else {
        result += letterValue;
      }
    }

    return result;
  }
}

void main() {
  Solution solution = Solution();

  for (String test in testList) {
    print("O número romano $test é equivalente a ${solution.romanToInt(test)}");
  }
}
