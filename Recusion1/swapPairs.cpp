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
    ListNode* swapPairs(ListNode* &head) {
        if (!head || !head->next){
            return head;
        }
        else {
            ListNode* nex=head->next;
            ListNode* next_next=nex->next;
            nex->next=head;
            ListNode* temp=head;
            head=nex;
            temp->next=swapPairs(next_next);
            return head;
        }
    }
};