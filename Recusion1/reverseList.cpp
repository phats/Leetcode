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
    ListNode*reverse(ListNode* &head, ListNode* prev){
        if (!head){
            return NULL;
        }
        else if (!head->next){
            head->next=prev;
            return head;
        }
        else {
            ListNode* nextNode=head->next;
            head->next=prev;
            return reverse(nextNode,head);
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        return reverse(head,prev);
    }
};