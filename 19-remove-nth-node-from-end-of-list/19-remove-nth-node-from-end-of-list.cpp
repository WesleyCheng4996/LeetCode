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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = head, **tar = &head;
        while(--n) {
            root = root->next;
        }
        while(root->next != nullptr) {
            root = root->next;
            tar = &(*tar)->next;
        }
        *tar = (*tar)->next;
        return head;
    }
};