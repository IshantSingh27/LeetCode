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
    TreeNode* sol(int prestart, int preend, vector<int>& pre, int instart, int inend, vector<int>& in, unordered_map<int , int>& inmap){
        if(prestart > preend || instart > inend) return NULL;

        int rv = pre[prestart];
        int ind = inmap[rv];
        int rem = ind - instart;

        TreeNode* root = new TreeNode(rv);

        root->left = sol(prestart + 1 , prestart + rem , pre , instart , ind - 1 , in , inmap);
        root->right = sol(prestart + rem + 1 , preend , pre , ind + 1 , inend , in , inmap);

        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = in.size();
        unordered_map<int , int> inmap;
        for(int i=0 ; i<n ; i++){
            inmap[in[i]] = i;
        }

        return sol(0 , n - 1 , pre , 0 , n - 1 , in , inmap);
    }
};