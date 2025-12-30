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

        return find(root->right);
    }

    TreeNode* solve(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;

        TreeNode* rootright = root->right;
        TreeNode* lastright = find(root->left);

        lastright->right = rootright;

        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return solve(root);

        TreeNode* cur = root;
        while(root != NULL){
            if(root->val < key){
                if(root->right && root->right->val == key){
                    root->right = solve(root->right);
                    break;
                }
                else root = root->right;
            }
            else{
                if(root->left && root->left->val == key){
                    root->left = solve(root->left);
                    break;
                }
                else root = root->left;
            }
        }

        return cur;
    }
};