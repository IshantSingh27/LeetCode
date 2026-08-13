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
    pair<int , int> sol(TreeNode* root){
        if(root == NULL) return {0 , INT_MIN};

        pair<int , int> left = sol(root->left);
        pair<int , int> right = sol(root->right);

        int maxi = max(left.second , right.second);

        if(root->val >= maxi) return {1 + left.first + right.first , max(maxi , root->val)};
        else return {left.first + right.first , max(maxi , root->val)};
    }
    int countDominantNodes(TreeNode* root) {
        return sol(root).first;
    }
};