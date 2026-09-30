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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {{}};
        map<int , map<int , multiset<int>>> mp;
        stack<pair<TreeNode* , pair<int , int>>> st;
        st.push({root , {0 , 0}});

        while(!st.empty()){
            TreeNode* temp = st.top().first;
            int x = st.top().second.first;
            int y = st.top().second.second;
            st.pop();

            mp[x][y].insert(temp->val);

            if(temp->left) st.push({temp->left , {x - 1 , y + 1}});
            if(temp->right) st.push({temp->right , {x + 1 , y + 1}});
        }

        vector<vector<int>> ans;
        for(auto it1 : mp){
            vector<int> temp;
            for(auto it2 : it1.second){
                for(auto it : it2.second){
                    temp.push_back(it);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};