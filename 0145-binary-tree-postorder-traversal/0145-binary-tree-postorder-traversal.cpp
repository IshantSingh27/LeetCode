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
        if(root == NULL) return ans;

        // post(root , ans);

        stack<TreeNode*> st2;
        st2.push(root);

        while(!st2.empty()){
            TreeNode* temp = st2.top();
            st2.pop();
            ans.push_back(temp->val);

            if(temp->left) st2.push(temp->left);
            if(temp->right) st2.push(temp->right);
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};