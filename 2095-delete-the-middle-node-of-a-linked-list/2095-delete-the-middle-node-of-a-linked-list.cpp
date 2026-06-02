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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = NULL;
        bool first = true;
        while(fast != NULL){
            fast = fast->next;

            if(fast != NULL){
                if(first){
                    slow = head;
                    first = false;
                }
                else{
                    slow = slow->next;
                }

                fast = fast->next;
            }
        }

        if(slow == NULL) return NULL;
        ListNode* temp = slow->next;
        if(temp){
            slow->next = temp->next;
            temp->next = NULL;
        }
        return head;
    }
};