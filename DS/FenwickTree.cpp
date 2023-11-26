#include <vector>
using namespace std;

class FenwickTree {
    vector<int> arr;
public:
    FenwickTree(int n) {
        arr.resize(n+1, 0);
    }
    int get(int i) {
        i++;
        int o = 0;
        while(i) {
            o += arr[i];
            i -= i&-i;
        }
        return o;
    }
    void update(int i, int x) {
        i++;
        while(i < arr.size()) {
            arr[i] += x;
            i += i&-i;
        }
    }
};