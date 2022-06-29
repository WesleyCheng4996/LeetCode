class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        head = swapn(head, head->next);
        return head;
    }
    ListNode* swapn(ListNode* n1, ListNode* n2) {
        if (n2 == nullptr) {
            return n1;
        }
        if(n2->next != nullptr)
            n2->next = swapn(n2->next, n2->next->next);
         n1->next = n2->next;
         n2->next = n1;
        return n2;

    }
};