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
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(root == NULL) return ans;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             TreeNode* node = st.top();
//             st.pop();

//             ans.push_back(node->val);

//             if(node->left) st.push(node->left);
//             if(node->right) st.push(node->right);
//         }
//         reverse(ans.begin() , ans.end());
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pre , post , in;
        if(root == NULL) return post;
        stack<pair<TreeNode* , int>> st;
        st.push({root , 1});

        while(!st.empty()){
            auto it = st.top();
            st.pop();

            if(it.second == 1){
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);

                if(it.first->left) st.push({it.first->left , 1});
            }
            else if(it.second == 2){
                in.push_back(it.first->val);
                it.second++;
                st.push(it);

                if(it.first->right) st.push({it.first->right , 1});
            }
            else{
                post.push_back(it.first->val);
            }
        }

        return post;
    }
};