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
    int getSize(ListNode *head){
        int count=0;
        while(head){
            ++count;
            head=head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA=getSize(headA),sizeB=getSize(headB);
        int n=sizeA-sizeB;
        ListNode *pointerA=headA,*pointerB=headB;
        if (n>0){
            while(n>0 && pointerA){
                pointerA=pointerA->next;
                --n;
            }
        }
        else{
            n=-n;
            while(n>0 && pointerB){
                pointerB=pointerB->next;
                --n;
            }
        }
        while(pointerA &&pointerB){
            if (pointerA==pointerB) return pointerA;
            pointerA=pointerA->next;
            pointerB=pointerB->next;
        }
        return NULL;
    }
};