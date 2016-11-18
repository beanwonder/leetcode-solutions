//
// Created by Zhebin Shen on 11/17/16.
//

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode fakehd(0);
        fakehd.next = head;
        RandomListNode fakenhd(0);

        unordered_map<RandomListNode*, RandomListNode*> old2new;
        // iterate twice
        RandomListNode *node = &fakehd;
        RandomListNode *nnode = &fakenhd;
        while (node->next) {
            nnode->next = new RandomListNode(node->next->label);
            nnode = nnode->next;
            node = node->next;
            old2new[node] = nnode;
        }

        old2new[NULL] = NULL;
        node = fakehd.next;
        nnode = fakenhd.next;
        while (node) {
            nnode->random = old2new[node->random];
            node = node->next;
            nnode = nnode->next;
        }

        return fakenhd.next;
    }
};

int main() {
    Solution s;
    s.copyRandomList(NULL);
}

