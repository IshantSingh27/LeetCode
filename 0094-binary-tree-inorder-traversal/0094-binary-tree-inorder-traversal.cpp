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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        // pre(root , ans);
        stack<TreeNode*> st;
        TreeNode* temp = root;

        while(temp != NULL || !st.empty()){
            while(temp){
                st.push(temp);
                temp = temp->left;
            }

            temp = st.top();
            st.pop();

            ans.push_back(temp->val);

            temp = temp->right;
        }

        return ans;
    }
};