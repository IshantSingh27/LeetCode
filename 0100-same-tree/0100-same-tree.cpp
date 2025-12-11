/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool same(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL) return p == q;

        if(p->val == q->val){
            if(!same(p->left , q->left)) return false;
            if(!same(p->right , q->right)) return false;
            return true;
        }
        else{
            return false;
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return same(p , q);
    }
};