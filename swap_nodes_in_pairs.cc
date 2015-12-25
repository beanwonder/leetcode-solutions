/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstddef>
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        // dummy node's next always points to head
        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = head;
        ListNode *prev = &dummy;
        ListNode *first = NULL;
        ListNode *second = NULL;

        while (cur != NULL) {
            first = cur;
            if (first->next != NULL) {
                // cur ptr go first
                cur = cur->next->next;
                second = first->next;
                prev->next = second;
                first->next = second->next;
                second->next = first;
                // exchanged first and second from now has exchanged
                prev = first;
            } else {
                break;
            }
        }
        return dummy.next;
    }

};
