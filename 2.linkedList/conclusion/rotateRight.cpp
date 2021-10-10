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
    void rotate(ListNode*& head){
        ListNode* preTail=new ListNode,*temp=head;
        //find previous Tail node
        while(temp->next->next){
            temp=temp->next;
        }
        preTail=temp;
        //Tail->next=head;
        preTail->next->next=head;
        //Update head=tail
        head=preTail->next;
        //remove Tail
        preTail->next=NULL;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        int size=getSize(head);
        k %=size;
        while(k>0){
            --k;
            rotate(head);
        }
        return head;
    }
};