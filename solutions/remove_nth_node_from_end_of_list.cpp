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
        ListNode* trav = head;
        int size=0;
        while(trav != NULL){
        size++;
        trav=trav->next;
        }
        if(size-n == 0){
            return head->next;
        }
        ListNode* curr = head;
        for(int i=0;i<size-n-1;i++){
        curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};