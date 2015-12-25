#include <vector>
#include <queue>
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
    ListNode* mergeKLists_k_way_merge(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        ListNode* cur = NULL;
        // minimum heap
        auto cmp = [](ListNode* xs, ListNode* ys) {return xs->val > ys->val;};
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> top_k(cmp);

        for (auto p : lists) {
            if (p) {
                top_k.push(p);
            }
        }
        if (top_k.empty()) {
            return head;
        } else {
            head = top_k.top();
            top_k.pop();
            if (head->next) {
                top_k.push(head->next);
            }
            cur = head;
        }
        while (!top_k.empty()) {
            ListNode *node = top_k.top();
            top_k.pop();
            if (node->next) {
                top_k.push(node->next);
            }
            cur->next = node;
            cur = node;
        }

        return head;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3 = NULL;
        ListNode *head = NULL;
        if (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                head = l1;
                l1 = l1->next;
            } else {
                head = l2;
                l2 = l2->next;
            }
        } else if (l1 != NULL) {
            head = l1;
            l1 = l1->next;
        } else if (l2 != NULL) {
            head = l2;
            l2 = l2->next;
        } else {
            return head;
        }    
        l3 = head;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                if (l1->val <= l2->val) {
                    l3->next = l1;
                    l3 = l3->next;
                    l1 = l1->next;
                } else {
                    l3->next = l2;
                    l3 = l3->next;
                    l2 = l2->next;
                }
            } else if (l1 != NULL && l2 == NULL) {
                l3->next = l1;
                break;
            } else {
                l3->next = l2;
                break;
            }
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        std::vector<ListNode*> lst(sz);
        while (sz != 1) {
            int cnt = 0;
            for (cnt = 0; cnt+1 < sz; cnt++) {

            }
        }
    }
};
