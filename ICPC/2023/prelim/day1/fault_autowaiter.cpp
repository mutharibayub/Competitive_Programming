#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <string> 

using namespace std;
 
typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

class FenwickTree {
    vector<int> __tree;
public:
    FenwickTree(int n) {
        __tree.resize(n+1, 0);
    }
    int get(int i) {
        i++;
        int out = 0;
        while(i) {
            out += __tree[i];
            i -= i&-i;
        }
        return out;
    }
    void update(int i, int upd) {
        i++;
        while(i < __tree.size()) {
            __tree[i] += upd;
            i += i&-i;
        }
    }
};

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int tttt=1;
    cin>>tttt;
    while(tttt--) {
        int n;
        cin >> n;
        int count = n;
        int jmp = 0;
        int nxt_idx = 0;
        FenwickTree fwt(n);
        for(int i = 0; i < n; i++) {
            fwt.update(i, +1);
        }
        auto get_index = [&](int i) -> int {
            if(!i && fwt.get(0) == 1) {
                return 0;
            }
            int l = 0, r = n-1;
            while (l < r) {
                int mid = (l+r+1)/2;
                int val = fwt.get(mid);
                if(val <= i) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            return l+1;
        };
        while (count > 1) {
            int actual_idx = get_index(nxt_idx);
            fwt.update(actual_idx, -1);
            count--;
            jmp++;
            nxt_idx += jmp;
            nxt_idx %= count;
        }
        cout << get_index(0)+1 << '\n';
    }
    return 0;
}