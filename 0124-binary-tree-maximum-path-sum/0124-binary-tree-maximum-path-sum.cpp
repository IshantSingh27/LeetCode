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
    int sol(TreeNode* root , int& maxi){
        if(root == NULL) return 0;

        int left = sol(root->left , maxi);
        int right = sol(root->right , maxi);

        maxi = max(maxi , root->val + left + right);

        return max(0 , root->val + max(left , right));
    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;

        sol(root , maxi);

        return maxi;
    }
};