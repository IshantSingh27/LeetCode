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
    TreeNode* lca(TreeNode* root , TreeNode* p , TreeNode* q){
        if(root == NULL) return NULL;
        if(root->val == p->val || root->val == q->val) return root;

        TreeNode* left = lca(root->left , p , q);
        TreeNode* right = lca(root->right , p , q);

        if(left && right) return root;
        else if(left) return left;
        else return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root , p , q);
    }
};