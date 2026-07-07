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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* pre = NULL , *cur = head , *temp = head->next;
        if(temp == NULL) return head;

        while(cur != NULL){
            cur->next = pre;
            pre = cur;
            cur = temp;
            if(temp != NULL) temp = temp->next;
        }

        return pre;
    }
};