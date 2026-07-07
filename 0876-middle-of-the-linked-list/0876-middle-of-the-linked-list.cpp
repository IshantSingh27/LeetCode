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
        ListNode* cur = head , *mid = head;
        while(cur != NULL){
            cur = cur->next;
            if(cur != NULL){
                mid = mid->next;
                cur = cur->next;
            }
        }
        return mid;
    }
};