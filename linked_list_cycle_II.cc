#include <unordered_set>
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
    ListNode *detectCycle_extra_space(ListNode *head) {
        // extra space
        std::unordered_set<ListNode *> pointers;
        ListNode *cur = head;
        while (cur != NULL) {
            if (pointers.find(cur) == pointers.end()) {
                pointers.insert(cur);
                cur = cur->next;
            } else {
                break;
            }
        }
        return cur;
    }

    ListNode *detectCycle(ListNode *head) {
        // two poniters
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // fist meet
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;

    }

};
