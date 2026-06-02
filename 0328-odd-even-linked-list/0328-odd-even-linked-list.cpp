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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *t1 , *t2 , *t3 , *t4;
        t2 = NULL;
        t4 = NULL;
        t1 = head;
        t3 = head->next;
        int cnt = 1;

        while(head != NULL){
            if(cnt % 2 == 1){
                if(t2 != NULL) t2->next = head;
                t2 = head;
            }
            else{
                if(t4 != NULL) t4->next = head;
                t4 = head;
            }
            head = head->next;
            cnt++;
        }

        t2->next = t3;
        t4->next = NULL;

        return t1;
    }
};