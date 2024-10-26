#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      if (n == 0) return;
      if (m == 0) {
        nums1 = nums2;
        return;
      }

      size_t n1 = 0;
      size_t n2 = 0;

      while (n1 < m + n && n2 < n) {
        if (n1 >= m + n2) {
          nums1[n1] = nums2[n2];
          n1++;
          n2++;
          continue;
        }
        if (nums2[n2] < nums1[n1]) {
          nums1.insert(nums1.begin() + n1, nums2[n2]);
          nums1.pop_back();
          n2++;
        }

        n1++;
      }

      nums1;
      
    }
};

int main() {
  auto solution = Solution();

  vector<int> nums1({1,2,3,0,0,0});
  vector<int> nums2({2,5,6});

  solution.merge(nums1,3,nums2,3);

  nums1;
}