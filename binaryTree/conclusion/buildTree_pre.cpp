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
    TreeNode* createNode(int data){
        TreeNode* p=new TreeNode;
        p->val=data;
        p->left=p->right=NULL;
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0||inorder.size()==0){
            return NULL;
        }
        TreeNode* root=createNode(preorder[0]);
        int index_mid=0;
        for (int i=0;i<inorder.size();i++){
            if (inorder[i]==root->val){
                index_mid=i;
                break;
            }
        }
        vector<int> left_in,left_pre,right_in,right_pre;
        if (index_mid<inorder.size()){
            left_in={inorder.begin(),inorder.begin()+index_mid};
            left_pre={preorder.begin()+1,preorder.begin()+index_mid+1};
        }
        if(index_mid<inorder.size()){
            right_in={inorder.begin()+index_mid+1,inorder.end()};
            right_pre={preorder.begin()+index_mid+1,preorder.end()};
        }
        root->left=buildTree(left_pre,left_in);
        root->right=buildTree(right_pre,right_in);
        return root;
    }
};