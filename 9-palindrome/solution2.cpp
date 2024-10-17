#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return false;

      char str[11];
      sprintf(str,"%u", x);

      size_t length = strSize2(str);

      return rec(str, length);
    }

    bool rec(char* c, size_t length) {
      if (length <= 1) return true;
      
      if (*c != c[length - 1]) return false;

      return rec(++c,length-2);
    }

    size_t strSize(char* c) {
      size_t length = 0;

      while (*c != '\0') {
        c++;
        length++;
      }

      return length;
    }

    size_t strSize2(char* c) {
      const char* ptr = c;

      while (*ptr != '\0') {
        ptr++;
      }

      return ptr - c;
    }
};

int main() {
  auto solution = Solution();

  vector<int> vec = {191,-12,4,888,891};

  for (int i : vec) {
    cout << "The number " << i << " is palindrome? " << solution.isPalindrome(i) << endl;
  }
}