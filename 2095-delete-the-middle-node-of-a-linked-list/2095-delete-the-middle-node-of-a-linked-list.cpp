/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode** fast = &head;
        ListNode** slow = &head;
        while(*fast != nullptr) {
            fast = &(*fast)->next;
            if(*fast != nullptr) {
                fast = &(*fast)->next;
                slow = &(*slow)->next;
            }
        }
        *slow = (*slow)->next;
        return head;
    }
};