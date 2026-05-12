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
    void solve(TreeNode* root , int& cnt , int k , int& ans){
        if(root == NULL) return;

        solve(root->left , cnt , k , ans);

        cnt++;
        if(cnt == k){
            ans = root->val;
        }

        solve(root->right , cnt , k , ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0 , ans = -1;
        solve(root , cnt , k , ans);
        return ans;
    }
};