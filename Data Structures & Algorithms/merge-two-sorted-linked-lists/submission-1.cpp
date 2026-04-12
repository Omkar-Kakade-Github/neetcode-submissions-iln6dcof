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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* retn_ptr = new ListNode(0);
        ListNode* f_ptr = retn_ptr;

        if(list1 == nullptr && list2 != nullptr){
            return list2;
        }

        else if(list2 == nullptr && list1 != nullptr){
            return list1;
        }

        else if(list2 == nullptr && list1 == nullptr){
            return nullptr;
        }

        while (list1 != nullptr && list2 != nullptr){
            if (list1->val <= list2->val){
                retn_ptr->next = list1;
                retn_ptr = retn_ptr->next;
                if (list1->next != nullptr){
                    list1 = list1->next;
                }
                else if (list1->next == nullptr){
                    retn_ptr->next = list2;
                    return f_ptr->next;
                } 
            }
            else if (list1->val >= list2->val){
                retn_ptr->next = list2;
                retn_ptr = retn_ptr->next;
                if (list2->next != nullptr){
                    list2 = list2->next;
                }
                else if (list2->next == nullptr){
                    retn_ptr->next = list1;
                    return f_ptr->next;
                } 
            }
        }

        return f_ptr->next;
    }
};
