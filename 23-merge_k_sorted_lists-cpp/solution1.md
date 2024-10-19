# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: **0ms** $$< 100\%$$
Add your time complexity here, e.g. $$O(M+N)$$

- Space complexity: **19.65mb** $$< 83.7\%$$
Add your space complexity here, e.g. $$O(1)$$

# Code
```cpp []

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

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
```