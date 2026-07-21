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
 class bstit{
    public:
    stack<TreeNode*> st;
    bool rev;
    bstit(TreeNode* root , bool reverse){
        rev = reverse;
        pushall(root);
    }
    int next(){
        if(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();

            if(rev) pushall(temp->left);
            else pushall(temp->right);

            return temp->val;
        }
        return -1;
    }
    bool hasnext(){
        return !st.empty();
    }
    void pushall(TreeNode* root){
        while(root != NULL){
            st.push(root);
            if(rev){
                root = root->right;
            }
            else root = root->left;
        }
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        bstit l(root , false);
        bstit r(root , true);

        int i = l.next() , j = r.next();
        while(i < j){
            if(i + j == k) return true;

            if(i + j < k){
                if(l.hasnext()) i = l.next();
                else break;
            }
            else{
                if(r.hasnext()) j = r.next();
                else break;
            }
        }

        return false;
    }
};