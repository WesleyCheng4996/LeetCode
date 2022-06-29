class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return head == nullptr? nullptr : swapn(head, head->next);
    }
    ListNode* swapn(ListNode* n1, ListNode* n2) {
        if (n2 == nullptr) {
            return n1;
        }
         n2->next = n2->next == nullptr ? nullptr : swapn(n2->next, n2->next->next);
         n1->next = n2->next;
         n2->next = n1;
        return n2;
    }
};