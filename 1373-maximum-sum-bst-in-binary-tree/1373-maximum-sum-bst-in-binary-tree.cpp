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
class nodeval{
    public:
    int maxi , mini , sum;
    nodeval(int ma , int mi , int sz){
        maxi = ma;
        mini = mi;
        sum = sz;
    }
};
class Solution {
public:
    int ans = 0;
    nodeval sol(TreeNode* root){
        if(root == NULL) return {INT_MIN , INT_MAX , 0};
        
        nodeval left = sol(root->left);
        nodeval right = sol(root->right);

        if(root->val > left.maxi && root->val < right.mini){
            int cur = left.sum + right.sum + root->val;
            ans = max(ans , cur);
            return {max(right.maxi , root->val) , min(left.mini , root->val) , cur};
        }
        else return {INT_MAX , INT_MIN , 0};
    }

    int maxSumBST(TreeNode* root) {
        sol(root);
        return ans;
    }
};