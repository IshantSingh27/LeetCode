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
        queue<pair<TreeNode* , pair<int , int>>> q;
        map<int , map<int , multiset<int>>> node;
        vector<vector<int>> ans;

        q.push({root , {0 , 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* temp = it.first;
            int x = it.second.first , y = it.second.second;
            node[x][y].insert(temp->val);
            if(temp->left) q.push({temp->left , {x - 1 , y + 1}});
            if(temp->right) q.push({temp->right , {x + 1 , y + 1}});
        }

        for(auto p : node){
            vector<int> cur;
            for(auto it : p.second){
                for(auto x : it.second){
                    cur.push_back(x);
                }
            }
            ans.push_back(cur);
        }

        return ans;
    }
};