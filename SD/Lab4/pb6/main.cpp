#include<vector>
using namespace std;
// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1 != nullptr) tail->next = l1;
        if (l2 != nullptr) tail->next = l2;
        return dummy.next;
    }
    ListNode* mergeSortLists(vector<ListNode*>& lists, int stanga, int dreapta) {
        if (stanga == dreapta) {
            return lists[stanga];
        }
        int mijloc = stanga + (dreapta - stanga) / 2;
        ListNode* stanga_rezolvata = mergeSortLists(lists, stanga, mijloc);
        ListNode* dreapta_rezolvata = mergeSortLists(lists, mijloc + 1, dreapta);
        return mergeTwoLists(stanga_rezolvata, dreapta_rezolvata);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeSortLists(lists, 0, lists.size() - 1);
    }
};