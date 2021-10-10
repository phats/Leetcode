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
    void addTail(ListNode* &head,ListNode* node){
        if (head == NULL) {
            head=node;
        }
        else {
            ListNode* temp=head;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=node;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        ListNode* temp=new ListNode;
        while(l1 && l2){
            if (l1->val <= l2->val){
                temp=l1;
                l1=l1->next;
                temp->next=NULL;
                addTail(head,temp);
            }
            else{
                temp=l2;
                l2=l2->next;
                temp->next=NULL;
                addTail(head,temp);
            }
        }
        while(l1){
            temp=l1;
            l1=l1->next;
            temp->next=NULL;
            addTail(head,temp);
        }
        while(l2){
            temp=l2;
            l2=l2->next;
            temp->next=NULL;
            addTail(head,temp);
        }
        return head;
    }
};