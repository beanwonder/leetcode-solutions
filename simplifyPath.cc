#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        int l = 0;
        int r = 0;
        
        while (l < path.size()-1 && path[l] == '/') {
            // skip //
            while (l < path.size() && path[l] == '/') {
                    // l += 1;
                l += 1;
            }
                
            r = l;
            while (r < path.size() && path[r] != '/') {
                // when leave r is either last one or start with a new slash
                r += 1;
            }
                
            // path start - r
            string d = path.substr(l, r - l);
            if (d == "..") {
                if (!dirs.empty()) {
                    dirs.pop_back();
                }
            } else if (!d.empty() && d != ".") {
                // normal stirng path
                dirs.push_back("/" + d);
            }
            // so l pointer to either last oen or a new slash
            l = r;
        }
        
        if (dirs.empty()) {
            return "/";
        } else {
            string simplified_path;
            for (auto dir : dirs) {
                simplified_path += dir;
            }
            return simplified_path;
        }
    }
};
