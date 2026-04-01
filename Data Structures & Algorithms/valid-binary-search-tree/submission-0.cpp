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
    bool helper(long left, long right, TreeNode* root){
        if(!root) return true;
        if(!(left<root->val && right> root->val)) return false;
        return helper(left,root->val, root->left) && helper(root->val,right, root->right);
    }
    bool isValidBST(TreeNode* root) {
        return helper(LONG_MIN, LONG_MAX, root);

        
    }


};
