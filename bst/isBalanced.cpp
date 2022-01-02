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
    int height(TreeNode* root) {
	    if (!root) {
		    return 0;
	    }
	    else {
		    if (root->left && root->right) {
			    return max(height(root->right),height(root->left))+1;
		    }
		    else if (root->left) {
		    	return height(root->left) + 1;
	    	}
    		else if (root->right) {
			    return height(root->right) + 1;
		    }
		    else {
			    return 1;
		    }
	    }
    }
    bool isBalanced(TreeNode* root) {
        if (!root) {
		    return true;
	    }
	    int balance = height(root->left)-height(root->right);
	    if (balance > 1 || balance < -1) return false;
	    else return isBalanced(root->left) && isBalanced(root->right);
    }
};