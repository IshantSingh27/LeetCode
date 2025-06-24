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
    void post(TreeNode* root , vector<int>& ans){
        if(root == NULL) return;

        post(root->left , ans);
        post(root->right , ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        // post(root , ans);
        // return ans;
        stack<TreeNode*> st;
        ans.push_back(root->val);
        if(root->left) st.push(root->left);
        if(root->right) st.push(root->right);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            
            ans.push_back(temp->val);

            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};