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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;

        while (cur != NULL || !s.empty()) { // Proper loop condition
            while (cur != NULL) { 
                s.push(cur);  // Push current node
                cur = cur->left;  // Move left
            }

            cur = s.top();
            s.pop();
            ans.push_back(cur->val); // Process node

            cur = cur->right; // Move to the right subtree
        }

        return ans;
    }
};
