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
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        ListNode* cur1 = h1 , *cur2 = h2;

        while(cur1 != cur2){
            if(cur1 == NULL){
                cur1 = h2;
            }
            else cur1 = cur1->next;

            if(cur2 == NULL){
                cur2 = h1;
            }
            else cur2 = cur2->next;
        }

        return cur1;
    }
};