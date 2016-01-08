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
    // think clear about the details of the algorithm in paper before write the code
    bool isPalindrome(ListNode* head) {
        // fast and slow pointer slow ptr reverse the list
        if (head == NULL || head->next == NULL) return true;

        ListNode *fst_ptr = head;
        ListNode *slw_ptr = head;
        ListNode *prev = NULL;
        ListNode *next = slw_ptr->next;
        ListNode *left = NULL;
        ListNode *right = NULL;

        while (fst_ptr != NULL) {
            fst_ptr = fst_ptr->next;
            if (fst_ptr != NULL) {
                fst_ptr = fst_ptr->next; 
                if (fst_ptr != NULL) {
                    slw_ptr->next = prev;
                    prev = slw_ptr;
                    slw_ptr = next;
                    next = slw_ptr->next;
                } else {
                    // move 2 step and fst_ptr became null
                    slw_ptr->next = prev;
                    // slow reach mid point in a even list
                    left = slw_ptr;
                    right = next;
                }
            } else {
                // fst_ptr == NULL when move one step
                // fst ptr reach the end of a odd list
                left = prev;
                right = next;
            }
        }

        while (left != NULL || right != NULL) {
            // left and right must reach mid point at same time
            // otherwise there is a bug
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
