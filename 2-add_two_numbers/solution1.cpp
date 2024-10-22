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

const vector<pair<vector<int>,vector<int>>> testList = {
  {{9,9,9,9},{9,9,9,9,9,9,9}},
  {{2,4,3},{5,6,4}},
};

ListNode* createList(vector<int> valueVec) {
  if (valueVec.size() == 0) return nullptr;

  ListNode* head = new ListNode(valueVec[0]);
  ListNode* currentNode = head;

  for (size_t i = 1 ; i < valueVec.size() ; i++) {
    auto tempNode = new ListNode(valueVec[i]);
    currentNode->next = tempNode;
    currentNode = tempNode;
  }

  return head;
}


class Solution {
  private:
    size_t getListSize(const ListNode* l, size_t currentSize = 0) {
      if (l->next == nullptr) return currentSize + 1;
      return getListSize(l->next, currentSize+1);
    }

    void orderLists(ListNode*& l1, ListNode*& l2) {
      size_t list1Size = getListSize(l1);
      size_t list2Size = getListSize(l2);

      if (list1Size >= list2Size) return;

      ListNode* temp = l1;
      l1 = l2;
      l2 = temp;
    }
  public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    orderLists(l1,l2);
    ListNode* head = l1;

    int carry = 0;

    while (true) {
      int currentVal = carry;

      currentVal += l1->val;

      if (l2 != nullptr) {
        currentVal += l2->val;
      }

      l1->val = currentVal % 10;

      carry = currentVal / 10;

      if (l1->next == nullptr) {
        break;
      }

      l1 = l1->next;

      if (l2 == nullptr & carry == 0) {
        break;
      }

      if (l2 != nullptr) {
        l2 = l2->next;
      }
    }

    if (carry > 0) {
      l1->next = new ListNode(carry);
    }

    return head;
  }
};

int main() {
  auto solution = Solution();

  ListNode* l1 = new ListNode(2);
  l1->next = new ListNode(4);

  for (auto test : testList) {
    auto result = solution.addTwoNumbers(createList(test.first), createList(test.second));
  }
}
