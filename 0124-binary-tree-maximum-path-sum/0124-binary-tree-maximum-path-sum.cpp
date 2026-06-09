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
    int sol(TreeNode* root , int& ans){
        if(root == NULL) return 0;

        int left = sol(root->left , ans);
        int right = sol(root->right , ans);

        ans = max(ans , root->val + left + right);

        return max(0 , root->val + max(left , right));
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        sol(root , ans);
        return ans;
    }
};