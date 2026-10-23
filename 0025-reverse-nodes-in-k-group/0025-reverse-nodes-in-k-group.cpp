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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        ListNode* cur = head , *temp = head;

        while(cur != NULL){
            int cnt = k - 1;
            vector<int> arr(k , 0);

            while(cnt >= 0 && cur != NULL){
                arr[cnt] = cur->val;
                cur = cur->next;
                cnt--;
            }

            if(cnt >= 0) break;

            int ind = 0;
            while(temp != cur){
                temp->val = arr[ind];
                ind++;
                temp = temp->next;
            }
        }

        return head;
    }
};