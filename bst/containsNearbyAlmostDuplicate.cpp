class Solution {
public:
    struct TreeNode{
        int val;
        TreeNode* left,*right;
    };
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
    void floorCeilBSTHelper(TreeNode* root, long long key, long long& floor, long long& ceil){
        while (root) {
            if (root->val == key) {
                ceil = root->val;
                floor = root->val;
                return;
            }
            if (key > root->val) {
                floor = root->val;
                root = root->right;
            }
            else {
                ceil = root->val;
                root = root->left;
            }
        }
        return;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k==0) return false;
        int n=nums.size();
        if (k>=n){
            k=n-1;
        }
        TreeNode* root=NULL;
        for (int i=0;i<n;i++){
            long long ceil=LLONG_MIN,floor=LLONG_MIN;
            floorCeilBSTHelper(root,nums[i],floor,ceil);
            cout<<ceil<<" "<<floor<<endl;
            if (floor!=LLONG_MIN && nums[i]-floor<=t){
                return true;
            }
            if (ceil!=LLONG_MIN && ceil-nums[i]<=t){
                return true;
            }
            root=insertIntoBST(root,nums[i]);
            if (i>=k){
                root=deleteNode(root,nums[i-k]);
            }
        }
        return false;
    }
};