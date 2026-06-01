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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }

        ListNode* temp;
        ListNode* cur = NULL;
        while(slow != NULL){
            temp = slow->next;
            slow->next = cur;
            cur = slow;
            slow = temp;
        }

        while(cur != NULL){
            if(head->val != cur->val) return false;
            head = head->next;
            cur = cur->next;
        }

        return true;
    }
};