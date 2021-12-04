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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root){
            return false;
        }
        else if (root->val==targetSum && !root->right && !root->left){
            return true;
        }
        else{
            targetSum-=root->val;
            if (hasPathSum(root->left,targetSum)){
                return true;
            }
            else{
                targetSum+=root->val;
            }
            targetSum-=root->val;
            if (hasPathSum(root->right,targetSum)){
                return true;
            }
            else{
                targetSum+=root->val;
            }
        }
        return false;
    }
};