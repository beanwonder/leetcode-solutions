/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 *
 */
#include <vector>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copied;
        return cloneGraph_dfs(copied, node);
    }

    UndirectedGraphNode* cloneGraph_dfs(unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>& copied, 
                   UndirectedGraphNode *copying) {
        if (copied.find(copying) != copied.end()) {
            return copied[copying];
        } else {
            UndirectedGraphNode *copy = new UndirectedGraphNode(copying->label);
            copied[copying] = copy;
            for (auto to_copy : copying->neighbors) {
                copy->neighbors.push_back(cloneGraph_dfs(copied, to_copy));
            }
            return copy;
        }
    }
};
