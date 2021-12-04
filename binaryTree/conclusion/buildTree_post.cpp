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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()==0 || postorder.size()==0){
            return NULL;
        }
        TreeNode* root=createNode(postorder[postorder.size()-1]);
        int index_mid=0;
        for (int i=0;i<inorder.size();i++){
            if (inorder[i]==root->val){
                index_mid=i;
                break;
            }
        }
        vector<int> left_in,left_post,right_in,right_post;
        left_in={inorder.begin(),inorder.begin()+index_mid};
        left_post={postorder.begin(),postorder.begin()+index_mid};
        right_in={inorder.begin()+index_mid+1,inorder.end()};
        right_post={postorder.begin()+index_mid,postorder.end()-1};
        root->left=buildTree(left_in,left_post);
        root->right=buildTree(right_in,right_post);
        return root;
    }
};