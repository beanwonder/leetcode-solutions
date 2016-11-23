#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

using namespace std;
class Pokemon {
public:
    double mAttack;
    double mDefense;
    double mStamina;
    double mLevel;

    Pokemon(double attack, double defense, double stamina, double level) {
        mAttack = attack;
        mDefense = defense;
        mStamina = stamina;
        mLevel = level;
    }

    Pokemon() {}
};

class CPMultiplier {
private:
    vector<double> mMultipliers;

public:
    CPMultiplier(vector<double> multipliers) {
        mMultipliers = multipliers;
    }

    double getMultiplierForLevel(double level) {
        if (level > 40.0) {
            return mMultipliers[78];
        }

        return mMultipliers[(int) (level * 2 - 2)];
    }

};


double squareRoot(double a) {
    return sqrt(a);
}

double roundToPlaces(double d, int numDecimalPlaces) {
    int scaleFactor = pow(10, numDecimalPlaces);
    return ((double)((int)(d * scaleFactor))) / scaleFactor;
}



/*
 * Complete the function below.
 */

double power_up(Pokemon& p, CPMultiplier& cpMultiplier) {
    double cpm = cpMultiplier.getMultiplierForLevel(p.mLevel);
    double old_cp = (p.mAttack * squareRoot(p.mDefense) * squareRoot(p.mStamina) * cpm * cpm) / 10;

    cpm = cpMultiplier.getMultiplierForLevel(p.mLevel + 0.5);
    double new_cp = (p.mAttack * squareRoot(p.mDefense) * squareRoot(p.mStamina) * cpm * cpm) / 10;

    return new_cp - old_cp;
}

double findMaximumCPGained(long numPowerUps, vector < Pokemon > pokemon, CPMultiplier cpMultiplier) {
    if (numPowerUps < 1) return 0;

    auto cmp = [&](Pokemon &p1, Pokemon &p2) {
        return power_up(p1, cpMultiplier) < power_up(p2, cpMultiplier);};

    priority_queue<Pokemon, vector<Pokemon>, decltype(cmp)> max_heap(cmp);

    // load all pokemon
    for (auto p : pokemon) {
        max_heap.push(p);
    }

    double max_cp = 0;
    while (numPowerUps > 0) {
        auto p = max_heap.top();
        max_cp += power_up(p, cpMultiplier);
        if (p.mLevel < 40) {
            p.mLevel += 0.5;
        }
        max_heap.pop();
        max_heap.push(p);
        numPowerUps -= 1;
    }
    return max_cp;
}

int main() {
    return 0;
}