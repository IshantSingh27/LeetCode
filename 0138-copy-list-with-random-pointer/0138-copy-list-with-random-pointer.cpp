/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insert(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* cur = new Node(temp->val);
            cur->next = temp->next;
            temp->next = cur;
            temp = temp->next->next;
        }
    }
    void random(Node* head){
        Node* temp = head;
        while(temp != NULL){
            if(temp->random != NULL) temp->next->random = temp->random->next;
            else temp->next->random = NULL;
            temp = temp->next->next;
        }
    }
    Node* next(Node* head){
        Node* dummy = new Node(-1) , *res = dummy , *temp = head;
        while(temp != NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            res = res->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        insert(head);
        random(head);
        return next(head);
    }
};