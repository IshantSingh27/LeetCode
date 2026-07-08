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
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;

        while(h1 != NULL || h2 != NULL || carry != 0){
            int sum = 0;
            if(h1 != NULL){
                sum += h1->val;
                h1 = h1->next;
            }
            if(h2 != NULL){
                sum += h2->val;
                h2 = h2->next;
            }
            sum += carry;

            int digit = sum % 10;
            ListNode* cur = new ListNode(digit);
            temp->next = cur;
            temp = temp->next;

            if(sum / 10 > 0) carry = (sum / 10) % 10;
            else carry = 0;
        }

        return dummy->next;
    }
};