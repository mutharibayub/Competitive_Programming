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

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int tttt=1;
    cin>>tttt;
    while(tttt--) {
        int n;
        cin >> n;
        vector<int> dp(n+1);
        for(int i = 0; i < n+1; i++) {
            dp[i] = i;
        }
        for(int i = 0; i < n+1; i++) {
            for(int j = i+3; j < n+1; j++) {
                dp[j] = max(dp[j], dp[i]*(j-i-1));
            }
        }
        cout << dp[n] << '\n';
    }
    return 0;
}