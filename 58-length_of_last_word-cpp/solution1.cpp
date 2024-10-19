#include <iostream>
#include <vector>

using namespace std;

const vector<string> testList = {
  "day    ",
  "a ",
  "Hello World",
  "   fly me   to   the moon  ",
  "luffy is still joyboy",
};

class Solution {
  public:
    int lengthOfLastWord(string s) {
      //If last char is space set last charId to be found,
      //If last char is valid, set the last id as the last char id
      int lastCharId = (s.back() == ' ') ? -1 : s.size() -1;

      for (int i = s.length() - 1 ; i >= 0 ; i--) {
        //If not found last char yet
        if (lastCharId == -1) {
          if (s[i] != ' ') {
            lastCharId = i;
          }
        }
        //Last char already found
        else {
          if (s[i] == ' ') {
            return lastCharId - i;
          }
        }
      }

      //If no second space is found, return the size of the first word, beginning at index 0, and ending at the lastCharId
      //therefore resulting in the index of the lastChar + 1
      return lastCharId + 1;
    }
};

int main() {
  auto solution = Solution();

  for (auto test : testList) {
    cout << solution.lengthOfLastWord(test) << endl;
  }
}