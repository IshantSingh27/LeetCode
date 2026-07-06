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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }
        k = k % len;
        if(k == 0) return head;
        tail->next = head;
        k = len - k - 1;
        while(k > 0){
            head = head->next;
            k--;
        }
        ListNode* temp = head->next;
        head->next = NULL;
        head = temp;

        return head;
    }
};