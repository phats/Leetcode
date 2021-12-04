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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in_order;
        if (!root) return in_order;
        vector<int> l=inorderTraversal(root->left);
        in_order.insert(in_order.end(),l.begin(),l.end());
        in_order.push_back(root->val);
        vector<int> r=inorderTraversal(root->right);
        in_order.insert(in_order.end(),r.begin(),r.end());
        return in_order;
    }
};