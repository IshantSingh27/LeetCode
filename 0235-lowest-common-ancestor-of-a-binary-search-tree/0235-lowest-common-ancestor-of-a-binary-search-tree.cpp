/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val)){
            return root;
        }

        if(root->val < p->val) return lca(root->right , p , q);

        else return lca(root->left , p , q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root , p , q);
    }
};