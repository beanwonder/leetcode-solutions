#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int max_product = 0;
        int words_size = words.size();
        std::vector<int> word_to_bits(words_size, 0);
        // sort > , for cut compare
        std::sort(words.begin(), words.end(), [](string s1, string s2){return s1.size() > s2.size();});
        // create bits map for each word
        for (int idx = 0; idx < words_size; idx++) {
            string str = words[idx];
            int str_len = str.size();
            int bits_map = 0;
            for (int i = 0; i < str_len; i++) {
                int offest = str[i] - 'a';
                bits_map |= 1 << offest;
            }
            word_to_bits[idx] = bits_map;
        }

        for (int i = 0; i < words_size; i++) {
            string s1 = words[i];
            int s1_len = s1.size();
            int s1_bits_map = word_to_bits[i];
            
            for (int j = i+1; j < words_size; j++) {
                string s2 = words[j];
                int s2_len = s2.size();
                int cur_product = s1_len * s2_len;
                if (cur_product > max_product) {
                    int s1_and_s2 = s1_bits_map & word_to_bits[j];
                    if (s1_and_s2 == 0) {
                        max_product = cur_product;
                    }
                } else {
                    // cut all remaining work
                    break;
                }
            }
        }

        return max_product;
    }
};
