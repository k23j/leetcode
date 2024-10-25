#include <iostream>
#include <vector>
#include <map>

using namespace std;

const vector<vector<int>> testList = {
  {1,2,2},
  {1,2,3,3,4,4,5},
  {1,1},
  {1,1,1},
  {1,1,1,2,3},
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* createList(vector<int>& vec) {
  ListNode* head = new ListNode(vec[0]);
  ListNode* current = head;

  for (size_t i = 1 ; i < vec.size() ; i++) {
    current->next = new ListNode(vec[i]);
    current = current->next;
  }

  return head;
}


class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      map<int,int> intMap;

      ListNode* ptr = head;

      while (ptr != nullptr) {
        intMap[ptr->val] += 1;

        ptr = ptr->next;
      }

      ListNode dummy = ListNode();
      ListNode* tail = &dummy;
      ptr = head;

      while (ptr != nullptr) {
        if (intMap[ptr->val] == 1) {
          tail->next = ptr;
          tail = tail->next;
        }

        ptr = ptr->next;
      }

      tail->next = nullptr;

      return dummy.next;
    }
};

int main() {
  auto solution = Solution();

  for (vector<int> test : testList) {
    auto result = solution.deleteDuplicates(createList(test));
    result;
  }
}