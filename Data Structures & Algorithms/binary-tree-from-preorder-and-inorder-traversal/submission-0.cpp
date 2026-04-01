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
    TreeNode* helper(int ps, int pe, vector<int>&preorder, int ins, int ine, vector<int>&inorder, unordered_map<int,int>&mpp){
        if(ps>pe || ins>ine) return nullptr ;
        TreeNode* root=new TreeNode(preorder[ps]);
        int inRoot=mpp[root->val];
        int numsLeft=inRoot-ins;
        root->left=helper(ps+1,ps+numsLeft, preorder,ins,inRoot-1,inorder,mpp);
        root->right=helper(ps+numsLeft+1, pe,preorder, inRoot+1, ine, inorder,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return helper(0,preorder.size()-1, preorder, 0, inorder.size()-1, inorder,mpp);
        
    }

};
