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
    TreeNode* build(int postart , int poend , vector<int>& po , int instart , int inend ,
    vector<int>& in , unordered_map<int , int>& inmap){
        if(instart > inend || postart > poend) return NULL;

        TreeNode* root = new TreeNode(po[poend]);
        int ind = inmap[po[poend]];
        int left = ind - instart;

        root->left = build(postart , postart + left - 1 , po , instart , ind - 1 , in , inmap);
        root->right = build(postart + left , poend - 1 , po , ind + 1 , inend , in , inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        unordered_map<int , int> inmap;
        for(int i=0 ; i<in.size() ; i++){
            inmap[in[i]] = i;
        }

        return build(0 , po.size() - 1 , po , 0 , in.size() - 1 , in , inmap);
    }
};