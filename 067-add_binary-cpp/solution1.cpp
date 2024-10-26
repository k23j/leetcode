#include <iostream>
#include <vector>

using namespace std;

const vector<pair<string,string>> testList = {
  {"1","11"},
  {"11","1"},
  {"111","111"},
  {"1010","1011"},
};

class Solution {
  private:
    void swap(string& a, string& b) {
      string temp = a;
      a = b;
      b = temp;
    }
  public:
    string addBinary(string a, string b) {

      if (a.length() < b.length()) swap(a,b);

      int carry = 0;

      for (int i = 0 ; i < a.length() ; i++) {
        int value = 0;
        if (a[a.length() -1 -i] == '1') value++;
        if (i < b.length() && b[b.length() - 1 -i] == '1') value++;

        if ((value + carry) == 0) {
          a[a.length() -1 -i] = '0';
          continue;
        }

        if ((value + carry) == 1) {
          a[a.length() -1 -i] = '1';
          if (carry > 0) carry--;
          continue;
        }

        if (value + carry == 2) {
          a[a.length() -1 -i] = '0';
          if (carry == 0) carry++;
          continue;
        }

        if (value + carry == 3) {
          a[a.length() -1 -i] = '1';
          continue;
        }
      }

      if (carry == 1) {
        a.insert(a.cbegin(), 1, '1');
      }

      return a;
    }
};

int main() {
  auto solution = Solution();

  for (auto test : testList) {
    auto result = solution.addBinary(test.first,test.second);
    cout << result << endl;
  }
}