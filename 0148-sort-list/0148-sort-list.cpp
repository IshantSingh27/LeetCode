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
    ListNode* find(ListNode* head){
        ListNode* fast = head , *slow = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            if(fast != NULL) slow = slow->next;
        }
        return slow;
    }
    ListNode* merger(ListNode* left , ListNode* right){
        ListNode* dummy = new ListNode(-1) , *cur = dummy;
        while(left != NULL && right != NULL){
            if(left->val < right->val){
                cur->next = left;
                left = left->next;
            }
            else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if(left != NULL){
            cur->next = left;
        }
        if(right != NULL){
            cur->next = right;
        }

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* middle = find(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return merger(left , right);
    }
};