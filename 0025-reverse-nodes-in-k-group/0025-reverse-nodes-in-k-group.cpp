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
ListNode* sol(ListNode* head, int k){
    k--;
    while(head != NULL && k > 0){
        head = head->next;
        k--;
    }
    if(k > 0) return NULL;
    else return head;
}
void reverse(ListNode* head){
    ListNode* temp = head->next , *prev = NULL;
    while(temp != NULL){
        head->next = prev;
        prev = head;
        head = temp;
        temp = temp->next;
    }
    head->next = prev;

}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode *pre = NULL , *temp = head;
        while(temp != NULL){
            ListNode* kn = sol(temp , k);
            if(kn == NULL){
                if(pre) pre->next = temp;
                break;
            }
            ListNode* nn = kn->next;
            kn->next = NULL;

            reverse(temp);

            if(temp == head) head = kn;
            else pre->next = kn;
            pre = temp;
            temp = nn;
        }
        return head;
    }
};