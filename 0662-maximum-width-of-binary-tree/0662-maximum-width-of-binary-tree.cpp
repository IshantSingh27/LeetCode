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
        if(root == NULL) return 0;

        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});
        long long ans = 1;

        while(!q.empty()){
            long long n = q.size();
            long long minx = q.front().second , start = 0 , end = 0;

            for(long long i=0 ; i<n ; i++){
                TreeNode* node = q.front().first;
                long long lvl = q.front().second - minx;
                q.pop();

                if(i == 0) start = lvl;
                if(i == n - 1) end = lvl;

                if(node->left) q.push({node->left , (2 * lvl) + 1});
                if(node->right) q.push({node->right , (2 * lvl) + 2});
            }

            ans = max(ans , (end - start + 1));
        }

        return ans;
    }
};