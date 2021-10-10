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
    int getSize(ListNode* head){
        int count=0;
        while(head){
            head=head->next;
            ++count;
        }
        return count;
    }
    void addTail(ListNode* &head,ListNode* node){
        if (head==NULL){
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
    ListNode* oddEvenList(ListNode* head) {
        int count=0;
        int size=getSize(head);
        ListNode* temp=head,*prev=new ListNode;
        prev->next=head;
        ListNode* saveTemp=new ListNode;
        while(temp && count <size){
            count++;
            if (count % 2==0){
                prev->next=temp->next;
                saveTemp=temp;
                temp=temp->next;
                saveTemp->next=NULL;
                addTail(head,saveTemp);
            }
            else{
                prev=prev->next;
                temp=temp->next;
            }
        }
        return head;
    }
};