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
    bool isMin(TreeNode* root,int data){
        if (root->right){
            root=root->right;
            while(root){
                if (root->val<=data){
                    return false;
                }
                root=root->left;
            }
        }
        return true;
    }
    bool isMax(TreeNode* root,int data){
        if (root->left){
            root=root->left;
            while(root){
                if (root->val>=data){
                    return false;
                }
                root=root->right;
            }
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if (root->left){
            if (root->val>root->left->val && isMax(root,root->val)){
                if(!isValidBST(root->left)) return false;
            }
            else {
                return false;
            }
        }
        if (root->right){
            if (root->val<root->right->val && isMin(root,root->val)){
                if(!isValidBST(root->right)) return false;
            }
            else {
                return false;
            }
        }
        return true;
    }
};