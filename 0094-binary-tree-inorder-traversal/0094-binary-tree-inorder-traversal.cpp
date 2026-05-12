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
    void pre(TreeNode* root , vector<int>& ans){
        if(root == NULL) return;

        pre(root->left , ans);
        ans.push_back(root->val);
        pre(root->right , ans);
    }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     if(root == NULL) return ans;
    //     // pre(root , ans);
    //     stack<TreeNode*> st;
    //     TreeNode* temp = root;

    //     while(temp != NULL || !st.empty()){
    //         while(temp){
    //             st.push(temp);
    //             temp = temp->left;
    //         }

    //         temp = st.top();
    //         st.pop();

    //         ans.push_back(temp->val);

    //         temp = temp->right;
    //     }

    //     return ans;
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> in;
        if(root == NULL) return in;

        while(cur != NULL){
            if(cur->left == NULL){
                in.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    in.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return in;
    }
};