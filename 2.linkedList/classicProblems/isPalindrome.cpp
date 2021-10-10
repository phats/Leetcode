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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* curr=head, *prev=NULL,*nextNode=head->next;
        while(nextNode){
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            nextNode=nextNode->next;
        }
        curr->next=prev;
        return curr;
    }
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL) return true;
        ListNode* fast=head,*slow=head;
        // find Middle node
        while(fast && fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        //reverse Right
        ListNode* reverseRight=reverseList(slow->next);
        // check
        ListNode* temp=head;
        while (temp && reverseRight){
            if (temp->val != reverseRight->val) return false;
            temp=temp->next;
            reverseRight=reverseRight->next;
        }
        return true;
    }
};