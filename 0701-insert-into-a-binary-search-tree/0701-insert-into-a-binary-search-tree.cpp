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
        if(root == NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }

        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->val < val){
                if(cur->right == NULL){
                    TreeNode* node = new TreeNode(val);
                    cur->right = node;
                    return root;
                }
                else{
                    cur = cur->right;
                }
            }
            else{
                if(cur->left == NULL){
                    TreeNode* node = new TreeNode(val);
                    cur->left = node;
                    return root;
                }
                else{
                    cur = cur->left;
                }
            }
        }
        return root;
    }
};