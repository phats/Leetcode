/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void remove(ListNode* &head,ListNode* &node){
        if (head == node){
            head=head->next;
            delete node;
            node=head;
            return;
        }
        else{
            ListNode* temp=head;
            ListNode* prev= new ListNode;
            prev->next=temp;
            if (node){
                while(temp){
                    if (temp==node){
                        prev->next=temp->next;
                        node=node->next;
                        delete temp;
                        return;
                    } 
                    else{
                        temp=temp->next;
                        prev=prev->next;
                    }
                }
            }
        }
    }
    ListNode* removeElements(ListNode* &head, int val) {
        ListNode* temp=head;
        while(temp){
            if (temp->val==val){
                remove(head,temp);
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};