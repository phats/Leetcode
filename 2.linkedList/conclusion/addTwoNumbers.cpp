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
    ListNode* createNode(int val){
        ListNode* node=new ListNode;
        node->next=NULL;
        node->val=val;
        return node;
    }
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        int odd=0;
        while(l1 && l2){
            odd +=l1->val+l2->val;
            addTail(head,createNode(odd%10));
            odd /=10;
            l1 = l1->next;
		    l2 = l2->next;
        }
        while(l1){
            odd += l1->val;
            addTail(head,createNode(odd%10));
            odd /=10;
            l1=l1->next;
        }
        while(l2){
            odd += l2->val;
            addTail(head,createNode(odd%10));
            odd /=10;
            l2=l2->next;
        }
        if (odd) addTail(head,createNode(1));
        return head;
    }
};