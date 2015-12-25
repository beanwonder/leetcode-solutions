/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 **/
#include <cstddef>
using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // fast and slow pointer
        ListNode *fst = head;
        ListNode *slw = head;
        while (fst != NULL) {
            slw = slw->next;
            fst = fst->next;
            if (fst != NULL) {
                fst = fst->next;
                if (fst == slw) {
                    return true;
                }
            }
        }
        return false;
    }
};
