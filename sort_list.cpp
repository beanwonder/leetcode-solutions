#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    bool comp_node(ListNode *&a, ListNode *&b) {
        return (a->val <= b->val);
    }

    ListNode* merge_list(ListNode *const l1, ListNode *const l2) {
        ListNode *l1_ptr = l1;
        ListNode *l2_ptr = l2;
        ListNode *head = NULL;
        ListNode *cur_ptr = NULL;

        if (comp_node(l1_ptr, l2_ptr)) {
            head = l1_ptr;
            l1_ptr = l1_ptr->next;
        } else {
           head = l2_ptr;
           l2_ptr = l2_ptr->next;
        }
        cur_ptr = head;

        while (l1_ptr || l2_ptr) {
            if (!l1_ptr) {
                // l1_ptr is NULL
                cur_ptr->next = l2_ptr;
                break;
            } else if (!l2_ptr) {
                cur_ptr->next = l1_ptr;
                break;
            } else {
                if (comp_node(l1_ptr, l2_ptr)) {
                    cur_ptr->next = l1_ptr;
                    cur_ptr = l1_ptr;
                    l1_ptr = l1_ptr->next;
                } else {
                    cur_ptr->next = l2_ptr;
                    cur_ptr = l2_ptr;
                    l2_ptr = l2_ptr->next;
                }
            }
        }
        return head;
    }

    int merge_sort(std::vector<ListNode*> &sublists_head, int size) {
        //int size = sublists_head.size();
        int size_after_merge = 0;

        if (size % 2 == 0) {
            size_after_merge = size / 2;
        } else {
            size_after_merge = size / 2 + 1;
        }

        for (int i = 0; i < size_after_merge; i++) {
            if ((2 * i + 1) < size) {
                sublists_head[i] = merge_list(sublists_head[2 * i], 
                                              sublists_head[2 * i + 1]);
            } else {
                // size is odd
                // then deal with the last one
                sublists_head[i] = sublists_head[2 * i];
            }
        }
        sublists_head.resize(size_after_merge);
        return size_after_merge;
    }

    // use merge sort o(nlogn) stable sort
    ListNode *sortList(ListNode *head) {
        std::vector<ListNode*> sublists_head;
        ListNode *node_ptr = head;
        if (head != NULL) {
            ListNode *tmp_node_ptr = NULL;
            while (node_ptr != NULL) {
                tmp_node_ptr = node_ptr;
                sublists_head.push_back(node_ptr);
                node_ptr = node_ptr->next;
                tmp_node_ptr->next = NULL;
            }
            // begin merge sort
            int size = sublists_head.size();
            while (sublists_head.size() > 1) {
                size = merge_sort(sublists_head, size);
            }
        } else {
            sublists_head.push_back(NULL);
        }
        return sublists_head.front();
    }

    void display(ListNode *const head) {
        ListNode *node_ptr = head;

        while (node_ptr != NULL) {
            cout << node_ptr->val << ' ';
            node_ptr = node_ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    ListNode *head;
    head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(4);

    //cout << "here";
    Solution s1;
    s1.display(head);
    //s1.sortList(head);
    s1.display(s1.sortList(head));

    return 0;
}

