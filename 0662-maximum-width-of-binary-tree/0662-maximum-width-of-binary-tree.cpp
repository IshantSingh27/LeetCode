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
        queue<pair<long long , TreeNode*>> q;
        q.push({0 , root});
        long long ans = 0;

        while(!q.empty()){
            long long n = q.size() , start = 0 , end = 0 , beg = q.front().first;

            for(long long i=0 ; i<n ; i++){
                long long ind = q.front().first - beg;
                TreeNode* temp = q.front().second;
                q.pop();

                if(i == 0) start = ind;
                if(i == n - 1) end = ind;

                if(temp->left) q.push({2 * ind , temp->left});
                if(temp->right) q.push({2 * ind + 1 , temp->right});
            }

            ans = max(ans , end - start + 1);
        }

        return ans;
    }
};