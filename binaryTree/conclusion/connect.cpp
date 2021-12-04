/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root){
            root->next=NULL;
            connet2Node(root->left,root->right);
        }
        return root;
    }
    void connet2Node(Node* r1,Node* r2){
        if (r1 && r2){
            r1->next=r2;
            r2->next=NULL;
            connet2Node(r1->left,r1->right);
            connet2Node(r1->right,r2->left);
            connet2Node(r2->left,r2->right);
        }
        else{
            return;
        }
        
    }
};