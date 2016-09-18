#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<vector<unsigned short>> part_products;
        for (int i = num2.size() - 1; i >= 0; --i) {
            part_products.push_back(vector<unsigned short> (num2.size() - i - 1 + num1.size(), 0));
            unsigned short n2 = num2[i] - '0';
            unsigned short carry = 0;
            for (int j = num1.size() - 1; j >= 0; --j) {
                unsigned short n1 = num1[j] - '0';
                unsigned short p = n1 * n2 + carry;
                carry = p / 10;
                part_products.back()[num1.size() - j - 1 + num2.size() - i - 1] = p % 10;
            }
            if (carry != 0) {
                part_products.back().push_back(carry);
            }
        }

        while (part_products.size() > 1) {
            vector<unsigned short> p1 = part_products.back();
            part_products.pop_back();
            vector<unsigned short> p2 = part_products.back();
            part_products.pop_back();

            vector<unsigned short>::size_type i = 0;
            int carry = 0;
            part_products.push_back(vector<unsigned short> (p1.size() > p2.size() ? p1.size() : p2.size(), 0));
            while (i < p1.size() || i < p2.size()) {
                if (i < p1.size() && i < p2.size()) {
                    unsigned short s = p1[i] + p2[i] + carry;
                    part_products.back()[i] = s % 10;
                    carry = s / 10;
                } else if (i < p1.size()) {
                    part_products.back()[i] = (p1[i] + carry) % 10;
                    carry = (p1[i] + carry) / 10;
                } else {
                    // i < p2.size()
                    part_products.back()[i] = (p2[i] + carry) % 10;
                    carry = (p2 [i] + carry) / 10;
                }
                i += 1;
            }

            if (carry != 0) {
                part_products.back().push_back(carry);
            }
        }

        string res;
        while (part_products.back().size() > 1 && part_products.back().back() == 0) {
                part_products.back().pop_back();
        }
        for (int i = part_products.back().size() - 1; i >= 0; --i) {
            res += (part_products.back()[i] + '0');
        }
        return res;
    }
};

int main() {
    Solution s;
    string ss = s.multiply("21", "443");
    return 0;
}
