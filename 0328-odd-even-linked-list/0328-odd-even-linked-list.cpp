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
    ListNode* oddEvenList(ListNode* odd) {
        if(odd == NULL) return odd;
        ListNode* ev = odd->next , *ohead = odd , *ehead = odd->next;
        if(ev == NULL) return odd;
        while(ev != NULL && ev->next != NULL){
            odd->next = ev->next;
            odd = odd->next;

            ev->next = odd->next;
            ev = ev->next;
        }
        odd->next = ehead;
        return ohead;
    }
};