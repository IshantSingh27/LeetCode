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
    TreeNode* build(vector<int>& pre, int prestart, int preend, vector<int>& in, int instart, int inend,
    unordered_map<int , int>& inmap){
        if(prestart > preend || instart > inend) return NULL;

        TreeNode* root = new TreeNode(pre[prestart]);
        int ind = inmap[pre[prestart]];
        int left = ind - instart;

        root->left = build(pre , prestart + 1 , prestart + left , in , instart , ind - 1 , inmap);
        root->right = build(pre , prestart + left + 1 , preend , in , ind + 1 , inend , inmap);

        return root;
     }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int , int> inmap;
        for(int i=0 ; i<in.size() ; i++){
            inmap[in[i]] = i;
        }

        return build(pre , 0 , pre.size() - 1 , in , 0 , in.size() , inmap);
    }
};