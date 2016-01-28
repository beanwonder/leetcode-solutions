#include <string>
#include <vector>
using namespace std;

class Solution {

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis_recr(res, "", n, 0, 0);
        return res;
    }

    void generateParenthesis_recr(vector<string>& res, string ps, 
                                  int &n, int leftp, int rightp) {
        // leftp and rightp means already printed "(" and ")"
        // leftp must >= rightp
        if (leftp == n && rightp == n) {
            res.push_back(ps);
        } else if (leftp == n) {
            generateParenthesis_recr(res, ps.append(")"), n, leftp, rightp+1);
        } else {
            if (leftp > rightp) {
                string ps2 = ps;
                generateParenthesis_recr(res, ps.append("("), n, leftp+1, rightp);
                generateParenthesis_recr(res, ps2.append(")"), n,  leftp, rightp+1);
            } else if (leftp == rightp) {
                generateParenthesis_recr(res, ps.append("("), n, leftp+1, rightp);
            } else {
                // should never reach here
                exit(-1);
            }
        }
    }
};
