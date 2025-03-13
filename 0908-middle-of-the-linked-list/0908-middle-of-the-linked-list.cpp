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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr1 = head;
        ListNode* curr2 = head;
        while(curr2->next != NULL && curr2->next->next != NULL){
            curr2 = curr2->next->next;
            curr1 = curr1->next;
        }

        if(curr2->next != NULL){
            return curr1->next;
        }
        else return curr1;
    }
};