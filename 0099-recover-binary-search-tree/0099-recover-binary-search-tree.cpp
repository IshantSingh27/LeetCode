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
private:
TreeNode *prev , *first , *middle , *last;
public:
    void in(TreeNode* root){
        if(root == NULL) return;

        in(root->left);
        if(prev != NULL){
            if(first == NULL && prev->val > root->val){
                first = prev;
                middle = root;
            }
            else if(prev->val > root->val){
                last = root;
                return;
            }
        }
        else{
            prev = root;
        }
        prev = root;
        in(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = prev = last = NULL;
        in(root);

        if(last == NULL){
            swap(first->val , middle->val);
        }
        else{
            swap(first->val , last->val);
        }
    }
};