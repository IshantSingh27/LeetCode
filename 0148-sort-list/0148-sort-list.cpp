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
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
    ListNode* merge(ListNode* h1 , ListNode* h2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(h1 && h2){
            if(h1->val < h2->val){
                temp->next = h1;
                h1 = h1->next;
            }
            else{
                temp->next = h2;
                h2 = h2->next;
            }
            temp = temp->next;
        }
        if(h1) temp->next = h1;
        else temp->next = h2;

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* middle = find(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        ListNode* lefthead = sortList(left);
        ListNode* righthead = sortList(right);

        return merge(lefthead , righthead);
    }
};