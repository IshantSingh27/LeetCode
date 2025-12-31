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
    TreeNode* first;
    TreeNode* last;
    TreeNode* prev;
    TreeNode* middle;
public:
    void in(TreeNode* root){
        if(root == NULL) return;

        in(root->left);

        if(prev != NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;

        in(root->right);
    }

    void recoverTree(TreeNode* root) {
        if(root == NULL) return;

        in(root);

        if(last == NULL){
            swap(first->val , middle->val);
        }
        else{
            swap(first->val , last->val);
        }
    }
};