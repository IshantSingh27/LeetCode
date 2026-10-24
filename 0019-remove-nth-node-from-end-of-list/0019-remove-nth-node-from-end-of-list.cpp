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
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* cur = head , *temp = head;
        while(n > 0){
            cur = cur->next;
            n--;
        }
        if(cur == NULL) return head->next;

        while(cur->next != NULL){
            cur = cur->next;
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return head;
    }
};