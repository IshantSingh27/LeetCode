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
    TreeNode* build(vector<int>& in, int instart, int inend, vector<int>& post, int poststart, int postend,
    unordered_map<long long , long long>& inmap){
        if(instart > inend || poststart > postend) return NULL;

        TreeNode* root = new TreeNode(post[postend]);
        long long ind = inmap[post[postend]];
        long long left = ind - instart;

        root->left = build(in , instart , ind - 1 , post , poststart , poststart + left - 1 , inmap);
        root->right = build(in , ind + 1 , inend , post , poststart + left , postend - 1 , inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<long long , long long> inmap;
        for(long long i=0 ; i<in.size() ; i++){
            inmap[in[i]] = i;
        }

        return build(in , 0 , in.size() - 1 , post , 0 , post.size() - 1 , inmap);
    }
};