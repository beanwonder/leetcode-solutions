#include <cstddef>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode fake(0);
        fake.next = head;
        ListNode *insert_pos = &fake;
        ListNode *cur = head;
        ListNode *prev = &fake;
        while (cur != NULL) {
            if (cur->val < x) {
                // insertion begin
                if (insert_pos->next != cur) {
                    prev->next = cur->next;
                    cur->next = insert_pos->next;
                    insert_pos->next = cur;

                    insert_pos = insert_pos->next;
                    // prev remain unchanged
                    cur = prev->next;
                } else {
                    insert_pos = insert_pos->next;
                    prev = cur;
                    cur = cur->next;
                }
                
            } else {
                // val >= x skip
                // insertion pos remain
                prev = cur;
                cur = cur->next;
            }
        }

        return fake.next;
    }
};
