#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <array>

using namespace std;

const int MOD = 1e9+7;

typedef long long ll;

ll pwr(ll n, ll e)
{
    ll out = 1;
    while(e)
    {
        if(e&1)out = (out*n)%MOD;
        e/=2;
        n=(n*n)%MOD;
    }return out;
}

int main() {
    
    vector<int> trees = {0, 1, 1, 3, 16, 125, 1296, 16807, 262144};

    int n, k;
    cin>>n>>k;

    cout << (1ll*k*trees[k]%MOD*pwr(n-k, n-k)%MOD) << '\n';

    return 0;
}