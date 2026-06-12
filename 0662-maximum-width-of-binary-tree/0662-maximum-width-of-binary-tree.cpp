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
        long long ans = 0;

        while(!q.empty()){
            long long n = q.size();
            long long lb = q.front().second , s = 0 , e = 0;

            for(long long i=0 ; i<n ; i++){
                TreeNode* temp = q.front().first;
                long long ind = q.front().second - lb;
                q.pop();

                if(i == 0) s = ind;
                if(i == n - 1) e = ind;

                if(temp->left) q.push({temp->left , 2 * ind});
                if(temp->right) q.push({temp->right , (2 * ind) + 1});
            }

            ans = max(ans , e - s + 1);
        }

        return ans;
    }
};