#include <cstring>
#include <iostream>
using namespace std;

class LRUCache{    
private:
    int capacity;
    int empty;
    int (*kvpair_array)[2];
public: 

    LRUCache(int capacity) {
        this->capacity = capacity;
        empty = capacity;
        kvpair_array = new int [capacity][2];
        memset(kvpair_array, 0, sizeof(int) * capacity * 2);
    }

    ~LRUCache(){
        delete[] kvpair_array;
    }

    int get(int key) {
        int value = -1;
        int top = capacity - empty - 1;
        int tmp[2];
        for (int i = 0; i < capacity - empty; i++) {
            if (kvpair_array[i][0] == key) {
                value = kvpair_array[i][1];
                // update LRU
                if (i != top) {
                    memcpy(tmp, kvpair_array + i, sizeof(tmp));
                    memcpy(kvpair_array + i, kvpair_array + i + 1, 2 * sizeof(int) * (top - i));
                    memcpy(kvpair_array + top, tmp, sizeof(tmp));
                }
                break;
            }
        }
        return value;
    }

    void set(int key, int value) {
        for (int i = 0; i < capacity - empty; i++) {
            if (kvpair_array[i][0] == key) {
                kvpair_array[i][1] = value;
                get(key);
                return;
            }
        }

        if (empty > 0) {
            int i = capacity - empty;
            --empty;
            kvpair_array[i][0] = key;
            kvpair_array[i][1] = value;
        } else {
            // replace
            // capacity is 0
            kvpair_array[0][0] = key;
            kvpair_array[0][1] = value;
            get(key);
        }
        return;
    }

    void display() {
        cout << "c" << capacity << ' ';
        cout << "empty" << empty << endl;
        for (int i = 0; i < capacity - empty; i++) {
            cout << kvpair_array[i][0] << ' ' << kvpair_array[i][1] << ' ';
        }
        cout << endl;
    }
};

int main(void)
{
    LRUCache l1(10);
    l1.set(7,28);
    l1.set(7,1);
    l1.set(8,15);
    cout << l1.get(6) << ' ';
    l1.set(10,27);
    l1.set(8,10);
    cout << l1.get(8) << ' ';
    l1.set(6,29);
    l1.set(1,9);
    cout << l1.get(6) << ' ';
    l1.set(10,7);
    cout << l1.get(1) << ' ';
    cout << l1.get(2) << ' ';
    cout << l1.get(13) << ' ';
    l1.set(8,30);
    l1.set(1,5);
    cout << l1.get(1) << ' ';
    l1.set(13,2);
    cout << l1.get(12) << ' ' << endl;
    return 0;
}
