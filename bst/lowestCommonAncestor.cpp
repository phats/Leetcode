/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root){
            return NULL;
        }
        else {
            int lower=min(p->val,q->val);
            int greater=max(p->val,q->val);
            if (root->val>=lower && root->val<=greater){
                return root;
            }
            else if (root->val>lower){
                return lowestCommonAncestor(root->left,p,q);
            }
            else {
                return lowestCommonAncestor(root->right,p,q);
            }
        }
    }
};