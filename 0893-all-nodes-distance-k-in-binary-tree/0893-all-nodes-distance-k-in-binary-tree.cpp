/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(cur->left){
                q.push(cur->left);
                parent[cur->left] = cur;
            }
            if(cur->right){
                q.push(cur->right);
                parent[cur->right] = cur;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* tar, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        solve(root , parent);

        unordered_map<TreeNode* , bool> vis;
        vis[tar] = true;
        queue<TreeNode*> q;
        q.push(tar);
        int cur = 0;

        while(!q.empty()){
            int n = q.size();
            if(cur++ == k) break;

            for(int i=0 ; i<n ; i++){
                TreeNode* cur = q.front();
                q.pop();

                if(cur->left && !vis[cur->left]){
                    q.push(cur->left);
                    vis[cur->left] = true;
                }
                if(cur->right && !vis[cur->right]){
                    q.push(cur->right);
                    vis[cur->right] = true;
                }
                if(parent[cur] && !vis[parent[cur]]){
                    q.push(parent[cur]);
                    vis[parent[cur]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};