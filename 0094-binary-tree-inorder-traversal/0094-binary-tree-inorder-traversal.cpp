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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            while(root->left != NULL){
                st.push(root->left);
                root = root->left;
            }
            
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if(node->right){
                st.push(node->right);
                root = node->right;
            }
        }

        return ans;
    }
};