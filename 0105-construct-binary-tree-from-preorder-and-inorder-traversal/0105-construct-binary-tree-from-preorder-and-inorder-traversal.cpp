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
    TreeNode* build(int prestart , int preend , vector<int>& pre , int instart , int inend ,
    vector<int>& in , unordered_map<int , int>& inmap){
        if(instart > inend || prestart > preend) return NULL;

        TreeNode* root = new TreeNode(pre[prestart]);
        int ind = inmap[pre[prestart]];
        int left = ind - instart;

        root->left = build(prestart + 1 , prestart + left , pre , instart , ind - 1 , in , inmap);
        root->right = build(prestart + left + 1 , preend , pre , ind + 1 , inend , in , inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int , int> inmap;
        for(int i=0 ; i<in.size() ; i++){
            inmap[in[i]] = i;
        }

        return build(0 , pre.size() - 1 , pre , 0 , in.size() - 1 , in , inmap);
    }
};