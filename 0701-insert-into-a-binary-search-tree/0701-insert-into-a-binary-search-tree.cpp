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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* cur = root , *ans = root;
        while(cur != NULL){
            ans = cur;
            if(cur->val > val){
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }
        if(val > ans->val) ans->right = new TreeNode(val);
        else ans->left = new TreeNode(val);

        return root;
    }
};