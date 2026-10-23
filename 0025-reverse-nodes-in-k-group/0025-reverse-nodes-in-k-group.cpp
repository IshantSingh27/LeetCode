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
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if(head == NULL || k == 1) return head;
    //     ListNode* cur = head , *temp = head;

    //     while(cur != NULL){
    //         int cnt = k - 1;
    //         vector<int> arr(k , 0);

    //         while(cnt >= 0 && cur != NULL){
    //             arr[cnt] = cur->val;
    //             cur = cur->next;
    //             cnt--;
    //         }

    //         if(cnt >= 0) break;

    //         int ind = 0;
    //         while(temp != cur){
    //             temp->val = arr[ind];
    //             ind++;
    //             temp = temp->next;
    //         }
    //     }

    //     return head;
    // }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pregroup = dummy;

        while(true){
            ListNode* temp = pregroup;

            for(int i=0 ; i<k && temp != NULL ; i++){
                temp = temp->next;
            }

            if(temp == NULL) break;

            ListNode* nextgroup = temp->next;
            ListNode* cur = pregroup->next;
            ListNode* pre = nextgroup;

            while(cur != nextgroup){
                ListNode* t = cur->next;
                cur->next = pre;
                pre = cur;
                cur = t;
            }

            ListNode* oldhead = pregroup->next; 
            pregroup->next = temp;
            pregroup = oldhead;
        }

        return dummy->next;
    }
};