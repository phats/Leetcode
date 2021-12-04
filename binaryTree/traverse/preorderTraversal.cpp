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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre_order;
        if (!root) return pre_order;
        pre_order.push_back(root->val);
        vector<int> l=preorderTraversal(root->left);
        pre_order.insert(pre_order.end(),l.begin(),l.end());
        vector<int> r=preorderTraversal(root->right);
        pre_order.insert(pre_order.end(),r.begin(),r.end());
        return pre_order;
    }
};