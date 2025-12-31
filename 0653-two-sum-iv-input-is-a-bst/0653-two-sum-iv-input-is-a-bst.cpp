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
class BSTIT{
    stack<TreeNode*> st;
    bool rev;

    void pushall(TreeNode* root){
        if(!rev){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
        }
        else{
            while(root != NULL){
                st.push(root);
                root = root->right;
            }
        }
    }

    public:
    BSTIT(TreeNode* root , bool reverse){
        rev = reverse;
        pushall(root);
    }

    int next(){
        TreeNode* node = st.top();
        st.pop();

        if(!rev){
            if(node->right){
                pushall(node->right);
            }
        }
        else{
            if(node->left){
                pushall(node->left);
            }
        }

        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        BSTIT s(root , false);
        BSTIT e(root , true);

        int i = s.next();
        int j = e.next();

        while(i < j){
            if(i + j == k) return true;

            if(i + j < k){
                i = s.next();
            }
            else if(i + j > k){
                j = e.next();
            }
        }

        return false;
    }
};