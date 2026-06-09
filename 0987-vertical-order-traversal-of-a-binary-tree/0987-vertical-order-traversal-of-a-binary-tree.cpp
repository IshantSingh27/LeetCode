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
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<pair<TreeNode* , pair<int , int>>> q;
        q.push({root , {0 , 0}});

        map<int , map<int , multiset<int>>> mp;

        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            mp[y][x].insert(temp->val);

            if(temp->left) q.push({temp->left , {x + 1 , y - 1}});
            if(temp->right) q.push({temp->right , {x + 1 , y + 1}});
        }

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