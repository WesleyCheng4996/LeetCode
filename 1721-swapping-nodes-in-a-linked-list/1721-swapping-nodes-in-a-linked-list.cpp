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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *k_node = head;
        for(int i = 1; i < k; ++i) {
            k_node = k_node->next;
        }
        ListNode *target_A_node = k_node, *target_B_node = head;
        while(k_node->next) {
            target_B_node = target_B_node->next;
            k_node = k_node->next;
        }
        if(target_A_node != target_B_node) {
           target_A_node->val ^= target_B_node->val ^= target_A_node->val ^= target_B_node->val;
        }
        return head;
    }
};