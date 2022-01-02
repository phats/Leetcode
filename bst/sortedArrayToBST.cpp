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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root){
            TreeNode* p=new TreeNode;
            p->val=val;
            p->left=p->right=NULL;
            return p;
        }
        else{
            if (val<root->val){
                root->left=insertIntoBST(root->left,val);
            }
            else{
                root->right=insertIntoBST(root->right,val);
            }
            return root;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0) return NULL;
        int middle=nums.size()/2;
        TreeNode* root=NULL;
        root=insertIntoBST(root,nums[middle]);
        if (middle>0){
            vector<int> l(nums.begin(),nums.begin()+middle);
            root->left=sortedArrayToBST(l);
        }
        if (middle<nums.size()-1){
            vector<int> r(nums.begin()+middle+1,nums.end());
            root->right=sortedArrayToBST(r);
        }
        return root;
    }
};