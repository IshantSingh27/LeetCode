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
    void sol(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& par){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left){
                par[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                par[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> par;
        sol(root , par);

        unordered_map<TreeNode* , bool> visit;
        queue<TreeNode*> q;
        visit[target] = 1;
        q.push(target);
        int cnt = 0;

        while(!q.empty()){
            int n = q.size();
            if(cnt++ == k) break;

            for(int i=0 ; i<n ; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left && !visit[temp->left]){
                    q.push(temp->left);
                    visit[temp->left] = 1;
                }
                if(temp->right && !visit[temp->right]){
                    q.push(temp->right);
                    visit[temp->right] = 1;
                }
                if(par[temp] && !visit[par[temp]]){
                    q.push(par[temp]);
                    visit[par[temp]] = 1;
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