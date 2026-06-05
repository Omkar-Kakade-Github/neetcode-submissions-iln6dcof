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
    bool hasCycle(ListNode* head) {
        if (!head) {
            return false;
        }

        std::map<ListNode*, int> count;

        while(!head) {
            count[head]++;

            if (count[head] > 1) {
                return true;
            }

            if (head->next == nullptr) {
                return false;
            }

            head = head->next;
        }
    }
};
