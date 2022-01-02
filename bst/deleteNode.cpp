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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val==val) return root;
        else if (val<root->val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root){
            return root;
        }
        else{
            if (root->val==key){
                if (root->right){ // have 2 child or child right
                    TreeNode* new_root=root->right;
                    TreeNode* parent=root;
                    while(new_root->left){
                        parent=new_root;
                        new_root=new_root->left;
                    }
                    if (new_root == root->right){
                        new_root->left=root->left;
                        //new_root->right=NULL;
                    }
                    else{
                        parent->left=new_root->right;
                        new_root->left=root->left;
                        new_root->right=root->right;
                    }
                    delete root;
                    return new_root;
                }
                else if (root->left){// have only child left
                    TreeNode* new_root=root->left;
                    delete root;
                    return new_root;
                }
                else{// no have child
                    delete root;
                    return NULL;
                }
            }
            else if (key<root->val){
                root->left=deleteNode(root->left,key);
            }
            else{
                root->right=deleteNode(root->right,key);
            }
            return root;
        }
    }
};