class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        k = k % count;
        if(k == 0) return head;
        temp = head;
        for(int i = 0; i < count - k - 1; i++){
            temp = temp->next;
        }
        ListNode* temp1 = temp->next;
        temp->next = NULL;
        ListNode* tail = temp1;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = head;
        return temp1;
    }
};
