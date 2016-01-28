class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_letter_cnt[26] = {0};
        int t_letter_cnt[26] = {0};
        bool ret = true;
        for (char ch : s) {
            s_letter_cnt[ch-'a']++;
        }
        
        for (char ch : t) {
            t_letter_cnt[ch-'a']++;
        }
        for (int i=0; i < 26; ++i) {
            if (s_letter_cnt[i] != t_letter_cnt[i]) {
                ret = false;
                break;
            } 
        }
        return ret;
    }
};
