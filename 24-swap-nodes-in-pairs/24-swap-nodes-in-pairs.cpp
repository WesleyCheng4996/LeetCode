class Solution {
public:
     ListNode* swapPairs(ListNode* head) {
        ListNode** indirect(&head), * a, * b;
        while ((a = *indirect) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *indirect = b;
            indirect = &a->next;
        }
        return head;
    }
};