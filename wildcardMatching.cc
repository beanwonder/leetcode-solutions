#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // DP solution
        // equation: 
        // MATCH(i, j) : is pattern p[0:i] match string s[0:j]
        //               / if p[i] is ch (s[j] == p[i] && MATCH(i-1, j-1)
        // MATCH(i, j) = - if p[i] is ?  MATCH(i-1, j-1)
        //               \ if p[i] is * any( MATCH(i-1, k) ) 0 <= k <= j
        // BC "" pattern only match "" string
        
        // first trim pattern
        //vector<char> trimed_p;
        //for (int i = 0; i < p.size(); ++i) {
        //    if (i == 0 || p[i] != '*' || (p[i] == '*' && p[i-1] != '*') ) {
        //        trimed_p.push_back(p[i]);
        //    }
        // }

        // actually when dp only consecutive two line are used
        vector<bool> memo(s.size()+1, false);
       
        // special case
        /* 
        for (int i = 1; i < p.size() + 1; ++i) {
            if (p[i-1] == '*') {
                memo[i][0] = true;
            } else {
                break;
            }
        }
        */
        
        // fill in memo
        // memo[0][0] = true
        memo[0] = true;
        for (int i = 1; i < p.size() + 1; ++i) {
            if (i > 1 && i < p.size() && p[i-2] == '*' && p[i-1] == '*') {
                continue;
            } else if (p[i-1] == '*'){
                for (int j = 1; j < s.size() + 1; ++j) {
                    memo[j] = memo[j] || memo[j-1];
                }
            } else {
                //(p[i-1] != '*')
                for (int j = s.size(); j > 0; --j) {
                    memo[j] = (p[i-1] == s[j-1] || p[i-1] == '?') && memo[j-1];
                }
                memo[0] = false;
            }

        }
        
        return memo[s.size()];
    }
};
