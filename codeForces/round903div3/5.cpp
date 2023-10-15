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

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<int> arr(n), dp(n+1, 1e9);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        dp[0] = 0;
        for(int i=0; i<n; i++)
        {
            dp[i+1] = min(dp[i+1], dp[i]+1);
            if(i+arr[i]<n)
                dp[i+arr[i]+1] = min(dp[i+arr[i]+1], dp[i]);
        }
        cout << dp[n] << '\n';
    }
    return 0;
}