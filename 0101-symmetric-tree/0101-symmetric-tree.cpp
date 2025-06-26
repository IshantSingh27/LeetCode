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
    bool symm(TreeNode* rl , TreeNode* rr){
        if(rr == NULL || rl == NULL) return (rr == rl);
        if(rr->val != rl->val) return false;

        return symm(rl->left , rr->right) && symm(rl->right , rr->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        else return symm(root->left , root->right);
    }
};