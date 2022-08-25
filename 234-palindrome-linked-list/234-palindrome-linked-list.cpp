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
    bool isPalindrome(ListNode* head) {
        int n = func(head);
        if(n < 2){
            return true;
        }
        int k = 0, j = head->val, i = 0;
        for(int curr = 0, end = n >> 1; curr < end; ++curr){
            k ^= curr + head->val;;
            head = head->next;
        }
        if((n & 1) == 1){
            head = head->next;
            --n;
        }
        for(int curr = n >> 1, end = n ; curr < end; ++curr){
            k ^= (n - curr - 1) + head->val;
            i = head->val;
            head = head->next;
        }
        return k == 0 && i == j;
    }
    int func(ListNode* head){
        int count = 0;
        while(head != nullptr){
            ++count;
            head = head->next;
        }
        return count;
    }
};