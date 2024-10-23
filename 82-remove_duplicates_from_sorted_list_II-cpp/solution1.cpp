#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> testList = {
  {1,1,1},
  {1,2,3,3,4,4,5},
  {1,1},
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
  private:
    ListNode* getNextUnique(ListNode*& node) {
      if (node == nullptr) return nullptr;

      if (node->next == nullptr) return node;

      if (node->val != node->next->val) return node;

      if (node->next->next == nullptr) return nullptr;

      ListNode* ptr = node->next->next;

      while (ptr->val == node->val || ptr == nullptr) {
        if (ptr == nullptr || ptr->next == nullptr) return nullptr;

        ptr = ptr->next;
      }

      return getNextUnique(ptr);
    }

  public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr) return nullptr;
      if (head->next == nullptr) return head;

      head = getNextUnique(head);

      if (head == nullptr) return nullptr;

      ListNode* ptr = head; 

      do {
        ptr->next = getNextUnique(ptr->next);
        ptr = ptr->next;
      } while (ptr != nullptr);

      return head;
    }
};

int main() {
  auto solution = Solution();

  for (vector<int> test : testList) {
    auto result = solution.deleteDuplicates(createList(test));
    result;
  }
}