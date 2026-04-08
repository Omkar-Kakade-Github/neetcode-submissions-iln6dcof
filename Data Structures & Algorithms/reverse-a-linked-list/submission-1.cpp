class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;

        while (curr != nullptr) {  
            nxt = curr->next;
            curr->next = ptr;
            ptr = curr;
            curr = nxt;
        }

        return ptr;
    }   
};