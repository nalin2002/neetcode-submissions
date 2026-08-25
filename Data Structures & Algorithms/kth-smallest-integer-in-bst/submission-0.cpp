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
    void preorder(TreeNode* root, vector<int>& ordered){
        if(!root) return;

        preorder(root->left, ordered);
        ordered.push_back(root->val);
        preorder(root->right,ordered);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;

        vector<int> ordered;
        preorder(root,ordered);

        return ordered[k-1];

    }
};
