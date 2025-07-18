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
    int flag=0;
    int dfs(TreeNode*root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int leftHeight=dfs(root->left);
        int rightHeight=dfs(root->right);
        if(abs(leftHeight-rightHeight)>1)
        {
            flag=1;
        }
        return max(leftHeight,rightHeight)+1;
    }
    int isBalanced(TreeNode* root) {
        dfs(root);
        if(flag) return false;
        return true;
    
    }
};
