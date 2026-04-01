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
    void helper(TreeNode* root, int&cnt, int maxi){
        if(!root) return;
        if(root->val >= maxi){
            cnt++;
            maxi=root->val;
        }
        helper(root->left, cnt, maxi);
        helper(root->right, cnt, maxi);
       

    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        helper(root,cnt,root->val);
        return cnt;
        
    }
};
