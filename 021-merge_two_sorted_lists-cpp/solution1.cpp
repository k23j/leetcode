#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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

const vector<pair<vector<int>,vector<int>>> testList = {
  {{2},{1}},
  {{1,2,4},{1,3,4}},
  {{},{}},
  {{},{0}},
  {{0},{0}},
};


class Solution {
  private:
    ListNode* getLower(ListNode*& a, ListNode*& b) {
      ListNode* result;

      if (a->val <= b->val) {
        result = a;
        a = a->next;
      } else {
        result = b;
        b = b->next;
      }

      return result;
    }

  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (list1 == nullptr) return list2;
      if (list2 == nullptr) return list1;

      ListNode* head = getLower(list1,list2);
      ListNode* current = head;

      while (list1 != nullptr && list2 != nullptr) {
          ListNode* lower = getLower(list1,list2);
          current->next = lower;
          current = lower;
      }

      current->next = ((list1 == nullptr) ? list2 : list1);

      return head;
    }
};



int main() {
  auto solution = Solution();

  // for (auto pair : testList) {
  //   ListNode* result = solution.mergeTwoLists(createList(pair.first), createList(pair.second));

  //   cout << (result == nullptr) << endl;
  // }
}