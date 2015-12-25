#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *tmplist_head = NULL;
        ListNode *tmpnode_ptr = NULL;
        ListNode *tmplist_ptr = NULL;
        ListNode *pretmplist_ptr = NULL;

        if (head != NULL) {
            tmplist_head = head;
            head = head->next;
            tmplist_head->next = NULL;
        }

        while (head != NULL) {
            tmpnode_ptr = head;
            head = head->next;
            tmplist_ptr = tmplist_head;
            if (tmplist_head->val > tmpnode_ptr->val) {
                tmpnode_ptr->next = tmplist_head;
                tmplist_head = tmpnode_ptr;
                continue;
            } else {
                pretmplist_ptr = tmplist_ptr;
                tmplist_ptr = tmplist_ptr->next;
                if (tmplist_ptr == NULL) {
                    pretmplist_ptr->next = tmpnode_ptr;
                    tmpnode_ptr->next = NULL;
                }
            }
            while (tmplist_ptr != NULL) {
                if (tmplist_ptr->val > tmpnode_ptr->val) {
                    pretmplist_ptr->next = tmpnode_ptr;
                    tmpnode_ptr->next = tmplist_ptr;
                    break;
                } else {
                    pretmplist_ptr = tmplist_ptr;
                    tmplist_ptr = tmplist_ptr->next;
                    if (tmplist_ptr == NULL) {
                        pretmplist_ptr->next = tmpnode_ptr;
                        tmpnode_ptr->next = NULL;
                    }
                }
            }
        }
        return tmplist_head;
    }
    void display(ListNode *head) {
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

    Solution s1;
    s1.display(head);
    s1.display(s1.insertionSortList(head));

    return 0;
}
