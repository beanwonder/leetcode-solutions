#include <cstddef>
using namespace std;
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode *fst = head;
        ListNode *slw = head; 
        ListNode *ptr = head;

        int len = 0;
        while (ptr != NULL) {
            ptr = ptr->next;
            len++;
        }
        k %= len;
        if (k == 0) return head;

        int cnt = 0;
        while (fst != NULL && cnt < k) {
            // move k th forward
            fst = fst->next;
            cnt++;
        }

        while (fst != NULL && fst->next != NULL) {
            slw = slw->next;
            fst = fst->next;
        }

        if (fst != NULL) {     
            ListNode* new_head = slw->next;
            slw->next = NULL;
            fst->next = head;
            head = new_head;
        }

        return head;
    }
};
