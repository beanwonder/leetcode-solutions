#include <iostream>
#include <vector>
#include <map>
using namespace std;

//  Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
 };
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        std::map<int, int> x_map;
        int max_dot = 0;
        for (vector<Point>::const_iterator i = points.begin(); i != points.end(); ++i) {
            x_map[i->y] += 1;
        }

        for (map<int, int>::const_iterator i = x_map.begin(); i != x_map.end(); ++i) {
            if (max_dot < i->second) {
                max_dot = i->second;
            }
        }
        return max_dot_x;
    }
};
