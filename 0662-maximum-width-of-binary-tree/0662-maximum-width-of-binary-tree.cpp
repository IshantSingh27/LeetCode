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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});
        long long ans = 0;

        while(!q.empty()){
            long long n = q.size();
            long long curx = q.front().second , minx , maxx;

            for(long long i=0 ; i<n ; i++){
                auto it = q.front();
                q.pop();

                TreeNode* temp = it.first;
                long long ind = it.second;
                if(i == 0) minx = ind;
                if(i == n - 1) maxx = ind;

                if(temp->left) q.push({temp->left , (2 * ind) - curx});
                if(temp->right) q.push({temp->right , ((2 * ind) + 1) - curx});
            }

            ans = max(ans , maxx - minx);
        }

        return ans + 1;
    }
};