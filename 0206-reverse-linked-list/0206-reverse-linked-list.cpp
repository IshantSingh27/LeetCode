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
    void rev(ListNode* &temp , ListNode* &cur , ListNode* &head){
        if(head == NULL) return;

        temp = head->next;
        head->next = cur;
        cur = head;
        head = temp;
        rev(temp , cur , head);
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* temp;
        ListNode* cur = NULL;
        rev(temp , cur , head);
        return cur;
    }
};