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
    unordered_map<string,bool> visitNode;
    //first: hash key (preorder) | second: check used (0 is used)
    string preorderTraversal(TreeNode* root,vector<TreeNode*>& res) {
        string pre_order;
        if (!root) return pre_order;
        pre_order+="c";
        pre_order+=to_string(root->val);
        
        string l=preorderTraversal(root->left,res);
        pre_order+="l";
        pre_order+=l;
        
        string r=preorderTraversal(root->right,res);
        pre_order+="r";
        pre_order+=r;
        
        auto got=visitNode.find(pre_order);
        if (got!=visitNode.end() && got->second==1){
            cout<<got->first<<endl;
            res.push_back(root);
            got->second=0;
        }
        else if (got==visitNode.end()){
            visitNode.insert({pre_order,1});
        }
        return pre_order;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        preorderTraversal(root,res);
        return res;
    }
};