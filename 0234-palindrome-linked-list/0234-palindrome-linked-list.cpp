class Solution {
public:
    ListNode* revlink(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* b1 = NULL;
        ListNode* a = head;
        ListNode* b2 = head->next;

        while(a != NULL){
            a->next = b1;
            b1 = a;
            a = b2;
            if(b2 != NULL) b2 = b2->next;
        }

        return b1;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revhead = revlink(slow);
        ListNode* t1 = head;
        ListNode* t2 = revhead;

        while(t2 != NULL){  // Only traverse the second half
            if(t1->val != t2->val) return false;
            t1 = t1->next;
            t2 = t2->next;
        }
        
        return true;
    }
};
