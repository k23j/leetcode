#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<pair<string,string>> testList = {
  {"sadbutsad","sad"},
  {"leetcode","leeto"},
};

class Solution {
  public:
    int strStr(string haystack, string needle) {
      if (haystack.length() < needle.length()) return -1;

      char first = needle[0];

      int occurrenceId = 0;

      while (occurrenceId <= haystack.length() - needle.length()) {
        if (haystack[occurrenceId] == first) {
          bool match = true;
          for (size_t i = 1 ; i < needle.length() ; i++) {
            if (haystack[occurrenceId + i] != needle[i]) {
              match = false;
              break;
            }
          }
          if (match) return occurrenceId;
        }

        occurrenceId++;
      }

      return -1;
    }
};

int main() {
  auto solution = Solution();

  for (auto test : testList) {
    auto result = solution.strStr(test.first, test.second);
    cout << result << endl;
  }
}