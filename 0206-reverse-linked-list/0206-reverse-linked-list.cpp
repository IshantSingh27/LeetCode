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
        if(head == NULL || head->next == NULL) return head;
        ListNode* b1 = NULL;
        ListNode* a = head;
        ListNode* b2 = head->next;
        while(b2 != NULL){
            a->next = b1;
            b1 = a;
            a = b2;
            b2 = b2->next;
        }
        a->next = b1;
        head = a;

        return head;
    }
};