/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* one = head;
        ListNode* two = head;
        while(two != NULL){
            two = two->next;
            if(two == NULL) return NULL;
            one = one->next;
            two = two->next;

            if(one == two){
                one = head;
                while(one != two){
                    one = one->next;
                    two = two->next;
                }
                return one;
            }
        }
        return NULL;
    }
};