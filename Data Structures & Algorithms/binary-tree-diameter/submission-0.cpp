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
    int maxheight(TreeNode* root){
        if(root==NULL) return 0;
        return 1+ max(maxheight(root->left),maxheight(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root==NULL) return 0;
        // if(root->left==NULL && root->right==NULL) return 0;

        // int leftHeight = maxheight(root->left);
        // int rightHeight = maxheight(root->right);
        // int diameter = leftHeight +rightHeight;

        // int left_right= max( diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));

        // return max(left_right,diameter);

        if(root==NULL) return 0;

        int res=0;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        int left= dfs(root->left, res);
        int right = dfs(root->right, res);
        res= max(res,left+right);
        return 1+max(left,right);
    }
};
