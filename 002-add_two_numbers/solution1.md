# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: **0ms** $$ <100\% $$
<$$O(n)$$

- Space complexity: **76.95mb** $$ < 97.76\% $$
$$O(1)$$

# Code
```cpp []

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

```
