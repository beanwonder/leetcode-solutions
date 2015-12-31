#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // hash table
        std::vector<string> res;
        int pos = 0;
        const int count = 10;
        const int str_sz = s.size();
        unordered_map<string, int> occured;

        while (pos + count - 1 < str_sz) {
            auto sub_str = s.substr(pos, count);
            auto search = occured.find(sub_str);
            if (search != occured.end()) {
                if (search->second == 1) {
                    res.push_back(sub_str);
                }
                search->second += 1;
            } else {
                occured.insert({sub_str, 1});
            }
            pos += 1;
        }
        return res;
    }

    int dna2int(char x) {
        switch (x) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default: return -1;
        }
    }

    vector<string> findRepeatedDnaSequences_bitset(string s) {
        // bit manupulate
        // A: 00 T: 01 C: 10 G: 11
        // bitmap 3 status 0 1 2 and more
        std::vector<string> res;
        int str_len = s.size();
        if (str_len < 10) return res;
        const int mask = (1 << 20) - 1;
        char bitmap[mask] = {0};
        
        // calc first 10 chars
        int str_hash = 0;
        for (int i = 0; i < 10; i++) { 
            str_hash = (str_hash << 2) | dna2int(s[i]);
        }
        bitmap[str_hash]++;

        for (int i = 10; i < str_len; i++) {
            str_hash = ((str_hash << 2) | dna2int(s[i])) & mask;
            //str_hash &= mask;
            switch (bitmap[str_hash]) {
                case 0:
                    bitmap[str_hash]++;
                    break;
                case 1:
                    bitmap[str_hash]++;
                    res.emplace_back(s.substr(i-9, 10));
                    break;
                case 2: 
                    break;
                default:
                    break;
            }
        }
        return res;
    }
};
