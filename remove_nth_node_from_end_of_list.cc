#include <iostream>
#include <vector>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //int count = n;
        std::vector<ListNode*> node_ptrs;
        ListNode *cur_ptr = head;
        while (cur_ptr != NULL) {
            node_ptrs.push_back(cur_ptr);
            cur_ptr = cur_ptr->next;
        }

        int to_rm_pos = node_ptrs.size() - n;
        if (to_rm_pos != 0) {
            node_ptrs[to_rm_pos-1]->next = node_ptrs[to_rm_pos]->next;    
        } else {
            head = head->next;
        }
        return head;
    }

    struct ListNode* removeNthFromEnd_faster(struct ListNode* head, int n) {
    // fast_ptr and slow_ptr
    //int count;
        if (head == NULL) {
            return head;
        }
        struct ListNode dummy_node(-1);
        dummy_node.next = head;
        struct ListNode* fst_ptr = &dummy_node;
        struct ListNode* slw_ptr = &dummy_node;
        // 
        for (int i = 1; i <= n; i++) {
            fst_ptr = fst_ptr->next;
        }
        while (fst_ptr->next) {
            slw_ptr = slw_ptr->next;
            fst_ptr = fst_ptr->next;
        }
        if (slw_ptr != &dummy_node) {
            slw_ptr->next = slw_ptr->next->next;
        } else {
            head = head->next;
        }
        return head;
}
};
