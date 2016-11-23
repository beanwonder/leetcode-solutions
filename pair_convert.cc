#include <iostream>
#include <set>
using namespace std;


bool convertable(pair<int, int> src, pair<int, int>& target) {
    if (src == target) {
        return true;
    } else if (src.first <= target.first && src.second <= target.second) {
        return convertable(pair<int, int> (src.first, src.second + src.first), target) ||  
               convertable(pair<int, int> (src.first + src.second, src.second), target);
    }
    return false;
}

bool convertable_pair(pair<int, int> src, pair<int, int>& target, set<pair<int, int>>& visited) {
    if (src == target) {
        return true;
    } else if (visited.find(src) == visited.end()) {
        if (src.first > 0 && src.second > 0) {
            if (src.first > target.first || src.second > target.second) {
                return false;
            }
        } else if (src.first < 0 && src.second < 0) {
            if (src.first < target.first || src.second < target.second) {
                return false;
            }
        }
        visited.insert(src);
        return convertable_pair(pair<int, int>(src.first, src.first+src.second), target, visited) 
               || convertable_pair(pair<int, int>(src.first+src.second, src.second), target, visited);
    }
    return false;
}

int main(void)
{
    pair<int, int> target(-34, -20);
    set<pair<int, int>> visited;
    cout << convertable_pair(pair<int, int> (-5, -4), target, visited) << endl;
    return 0;
}
