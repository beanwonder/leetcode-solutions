//
// Created by Zhebin Shen on 11/17/16.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    void reorderList(ListNode* head) {
        // first split
        if (!head || !head->next) return;
        ListNode *p1 = head, *p2 = head->next;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        // then reverse second half
        // p1 is at half pos
        ListNode *head2 = p1->next;
        p1->next = NULL;

        p2 = head2;
        ListNode *prev = NULL;

        while (p2) {
            ListNode* next = p2->next;
            p2->next = prev;
            prev = p2;
            p2 = next;
        }
        // prev now is the head of the second list

        // finally merge two
        p1 = head;
        p2 = prev;
        while (p2) {
            ListNode *p1next = p1->next;
            ListNode *p2next = p2->next;
            p1->next = p2;
            p2->next = p1next;
            p1 = p1next;
            p2 = p2next;
        }
    }

    void reorderList_naive(ListNode* head) {
        // naive solution
        // first find the last node
        if (head) {
            ListNode fakehd(0);
            fakehd.next = head;
            ListNode *second_to_last = &fakehd;
            ListNode *last = head;
            ListNode *cur = head;
            ListNode *second_to_hd = head->next;
            while (cur->next) {
                second_to_last = cur;
                cur = cur->next;
                last = cur;
            }
            if (last != head && second_to_last != head) {
                // must deal with base cases
                head->next = last;
                second_to_last->next = NULL;
                last->next = second_to_hd;
                reorderList(second_to_hd);
            }
        }


    }
};