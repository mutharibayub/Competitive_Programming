#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <queue>
#include <functional>
#include <limits>
#include <numeric>

using namespace std;

typedef long long ll;
template<typename T> using MinPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt;
    cin >> tttt; 
    int q;
    cin >> q;
    while (tttt--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                arr[j] = abs(arr[j+1]-arr[j]);
            }
        }
        for(int i = 0; i < n - 2; i++) {
            cout << (arr[i]>=q? 1: 0) << " \n"[i==n-3];
        }
    }
    return 0;
}