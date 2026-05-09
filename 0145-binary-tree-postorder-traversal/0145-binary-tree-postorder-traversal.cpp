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
    // void pre(TreeNode* root , vector<int>& ans){
    //     if(root == NULL) return;

    //     pre(root->left , ans);
    //     pre(root->right , ans);
    //     ans.push_back(root->val);
    // }

    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     if(root == NULL) return ans;
    //     // pre(root , ans);
    //     // stack<TreeNode*> st;
    //     // st.push(root);
    //     // while(!st.empty()){
    //     //     TreeNode* temp = st.top();
    //     //     st.pop();

    //     //     ans.push_back(temp->val);

    //     //     if(temp->left) st.push(temp->left);
    //     //     if(temp->right) st.push(temp->right);
    //     // }

    //     // reverse(ans.begin() , ans.end());

    //     stack<TreeNode*> st;
    //     TreeNode* temp = root;
    //     while(temp != NULL || !st.empty()){
    //         if(temp){
    //             st.push(temp);
    //             temp = temp->left;
    //         }
    //         else{
    //             TreeNode* cur = st.top()->right;
    //             if(cur == NULL){
    //                 cur = st.top();
    //                 st.pop();
    //                 ans.push_back(cur->val);
    //                 while(!st.empty() && cur == st.top()->right){
    //                     cur = st.top();
    //                     st.pop();
    //                     ans.push_back(cur->val);
    //                 }
    //             }
    //             else temp = cur;
    //         }
    //     }

    //     return ans;
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pre , in , post;
        if(root == NULL) return pre;

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