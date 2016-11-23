#include <vector>
#include <iostream>
#include <string>
using namespace std;


int lcs_dp2(string s1, string s2) {
    int s1_len = s1.size();
    int s2_len = s2.size();
    // s2_len+1 for special case 
    vector<vector<int>> memo(s1_len+s2_len, vector<int> (s2_len+1, 0));
    int max = 0;
    for (int i=0; i < memo.size(); ++i) { 
        // j start with 1 means compare with 
        for (int j=1; j <= s2_len; ++j) {
            // start with s2[0] 
            // compare with s2[j-1] with s1[pos]
            int pos = i - (s2_len - j);
            if (pos >= 0 && pos < s1_len) {
                if (s1[pos] == s2[j-1]) {
                    memo[i][j] = memo[i][j-1] + 1;
                    if (memo[i][j] > max) {
                        max = memo[i][j];
                    }
                }
            }
        }
    }

    return max;
}


int lcs_suffex_tree(string s, string t) {
   return 0; 
}

int lcs_dp(string s, string t) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> memo(m, vector<int> (n, 0));

    // fill the memo
    int max;
    for (int i=0; i < m; ++i) {
        for (int j=0; j < n; ++j) {
            if (s[i] == t[j]) {
                if (i == 0 || j == 0) {
                    memo[i][j] = 1;
                } else {
                    memo[i][j] = memo[i-1][j-1] + 1;
                }
                if (memo[i][j] > max) {
                    max = memo[i][j];
                }
            }
        }
    }
    return max;
}

int main(void)
{
    cout << lcs_dp("a", "a");
    cout << lcs_dp("aa", "aa");
    cout << lcs_dp("aaacd", "acdb");
    cout << lcs_dp("abcdefg", "abcdefg");
    return 0;
}
