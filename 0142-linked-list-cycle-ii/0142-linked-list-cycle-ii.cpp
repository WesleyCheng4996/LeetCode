/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*>st;
        st.insert(nullptr);
        while(head != nullptr) {
            if(st.count(head) == 0) {
                st.insert(head);
            } else {
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }
};