#include <cstddef>
#include <math.h>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int cntA = 0;
        int cntB = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        
        while ((curA != NULL) || (curB != NULL)) {
            if (curA != NULL) {
                curA = curA->next;
                cntA += 1;
            }
            if (curB != NULL) {
                curB = curB->next;
                cntB += 1;
            }
        }
        
        ListNode *longPtr = cntA >= cntB ? headA : headB;
        ListNode *shortPtr = cntA < cntB ? headA : headB;
        int diff = abs(cntA-cntB);
        for (int i=0; i < diff; ++i) {
            longPtr = longPtr->next;
        }
        
        while ((longPtr != NULL) && (shortPtr != NULL)) {
            if (longPtr == shortPtr) {
                return longPtr; // got it
            } else {
                longPtr = longPtr->next;
                shortPtr = shortPtr->next;
            }
        }
        return NULL; // NULL
    }
};
