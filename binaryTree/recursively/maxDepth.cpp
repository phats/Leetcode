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
    int maxDepth(TreeNode* root) {
        int maxDep=1;
        if (root){
            if (root->left){
                maxDep=max(maxDep,maxDepth(root->left)+1);
            }
            if (root->right){
                maxDep=max(maxDep,maxDepth(root->right)+1);
            }
        }
        else {
            return 0;
        }
        return maxDep;
    }
};