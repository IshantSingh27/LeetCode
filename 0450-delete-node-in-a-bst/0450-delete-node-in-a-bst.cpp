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
    TreeNode* find(TreeNode* root){
        if(root->right == NULL) return root;
        else return find(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;

        TreeNode* rightchild = root->right;
        TreeNode* lastright = find(root->left);
        lastright->right = rightchild;

        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int k) {
        if(root == NULL) return root;
        if(root->val == k) return helper(root);
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->val > k){
                if(cur->left != NULL && cur->left->val == k){
                    cur->left = helper(cur->left);
                    break;
                }
                else{
                    cur = cur->left;
                }
            }
            else{
                if(cur->right != NULL && cur->right->val == k){
                    cur->right = helper(cur->right);
                    break;
                }
                else{
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};