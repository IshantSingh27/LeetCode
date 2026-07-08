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
        if(head == NULL) return head;
        ListNode* temp = head , *del = head;

        while(temp != NULL && n > 0){
            temp = temp->next;
            n--;
        }
        if(temp == NULL) return head->next;

        while(temp->next != NULL){
            temp = temp->next;
            del = del->next;
        }

        del->next = del->next->next;

        return head;
    }
};