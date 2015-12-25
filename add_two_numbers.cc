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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1_ptr = l1;
        ListNode *l2_ptr = l2;
        ListNode *sum_lst_head = new ListNode(-1);
        //listNode *sum_prev_ptr - sum_lst;
        // sum_ptr never NULL
        ListNode *sum_ptr = sum_lst_head;
        bool carry_flg = false;
    
        while (l1_ptr != NULL || l2_ptr != NULL || carry_flg) {
            // iterate over two list
            int sum = 0, 
                ones = 0;
            if (l1_ptr != NULL && l2_ptr != NULL) {
                sum = (l1_ptr->val + l2_ptr->val);
                l1_ptr = l1_ptr->next;
                l2_ptr = l2_ptr->next;
            } else {
                if (l1_ptr != NULL) {
                    sum = l1_ptr->val;
                    l1_ptr = l1_ptr->next;
                } else if (l2_ptr != NULL) {
                    sum = l2_ptr->val;
                    l2_ptr = l2_ptr->next;
                }
            }
            sum += carry_flg ? 1 : 0;
            ones = sum % 10;
            carry_flg = (sum / 10) == 1;
            if (sum_ptr != NULL) {
                sum_ptr->next = new ListNode(ones);
                sum_ptr = sum_ptr->next;
            } else {
                abort();
            }
        }
        return sum_lst_head->next;
    }
};

int main(void)
{
    // tests
    
    return 0;
}
