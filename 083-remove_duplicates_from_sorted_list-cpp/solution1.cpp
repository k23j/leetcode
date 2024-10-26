#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr) return nullptr;

      ListNode* ptr = head;
      ListNode* del;

      while (ptr->next != nullptr) {
        if (ptr->val == ptr->next->val) {
          del = ptr->next;
          ptr->next = del->next;
          delete del;
        } else {
          ptr = ptr->next;
        }
      }

      return head;
    }
};

int main() {
  auto solution = Solution();
}