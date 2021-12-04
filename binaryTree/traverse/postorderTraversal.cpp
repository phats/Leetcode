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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post_order;
        if (!root) return post_order;
        vector<int> l=postorderTraversal(root->left);
        post_order.insert(post_order.end(),l.begin(),l.end());
        vector<int> r=postorderTraversal(root->right);
        post_order.insert(post_order.end(),r.begin(),r.end());
        post_order.push_back(root->val);
        return post_order;
    }
};