#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return false;

      string y = to_string(x);

      return rec(&y);
    }

    bool rec(string* str) {
      if (str->length() <= 1) return true;
      
      if (str->front() != str->back()) return false;

      *str = str->substr(1,str->length() - 2);

      return rec(str);
    }
};

int main() {
  auto solution = Solution();

  vector<int> vec = {191,-12,4,888,891};

  for (int i : vec) {
    cout << "The number " << i << " is palindrome? " << solution.isPalindrome(i) << endl;
  }
}