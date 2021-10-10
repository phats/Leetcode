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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode;
        dummy->next=head;
        ListNode* left=dummy,*right=head;
        while(n>0 && right){
            right=right->next;
            --n;
        }
        while(right){
            right=right->next;
            left=left->next;
        }
        ListNode* temp=left->next;
        left->next=left->next->next;
        delete temp;
        return dummy->next;
    }
};