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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* nxt = cur->next;
        int minind = -1 , mostmin = -1 , mini = INT_MAX , i = 1;

        while(nxt != NULL){
            if((cur->val > prev->val && cur->val > nxt->val) || 
            (cur->val < prev->val && cur->val < nxt->val)){
                if(minind == -1){
                    minind = i;
                    mostmin = i;
                }
                else{
                    mini = min(mini , i - minind);
                    minind = i;
                }
            }
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
            i++;
        }
        cout<<"minind : "<<minind<<" mostmin: "<<mostmin<<endl;
        if(mini == INT_MAX || minind == mostmin) return {-1 , -1};

        return {mini , minind - mostmin};
    }
};