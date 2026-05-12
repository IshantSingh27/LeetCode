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
    TreeNode* sol(TreeNode* root){
        if(root->right == NULL) return root;

        else return sol(root->right);
    }

    TreeNode* help(TreeNode* root){
        if(root->right == NULL) return root->left;
        if(root->left == NULL) return root->right;

        TreeNode* rightchild = root->right;

        TreeNode* leftchild = sol(root->left);

        leftchild->right = rightchild;

        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int k) {
        if(root == NULL) return NULL;

        if(root->val == k) return help(root);

        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->val >= k){
                if(cur->left && cur->left->val == k){
                    cur->left = help(cur->left);
                    break;
                }
                else cur = cur->left;
            }
            else{
                if(cur->right && cur->right->val == k){
                    cur->right = help(cur->right);
                    break;
                }
                else cur = cur->right;
            }
        }

        return root;
    }
};