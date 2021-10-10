/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* intersection(ListNode *head){
        if (head == NULL || head->next==NULL){
            return NULL;
        }
        ListNode *fast=head,*slow=head;
        while(fast && slow && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if (fast==slow && slow){
                return slow;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *res=intersection(head);
        if (res==NULL) return NULL;
        ListNode *nor=head;
        while (nor != res){
            res=res->next;
            nor=nor->next;
        }
        return nor;
    }
};