#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

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
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i].first, arr[i].second=i;
        sort(arr.rbegin(), arr.rend());
        vector<int> secArr;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<arr[i].first;j++)
            {
                secArr.push_back(arr[i].second);
            }
        }
        int ptr = 0;
        while(ptr<secArr.size()&&(secArr[ptr]==arr[0].second||ptr<secArr.size()/2))ptr++;
        vector<pair<int,int>> ans;
        for(int i=0;i<ptr&&i+ptr<secArr.size();i++)
        {
            ans.emplace_back(secArr[i], secArr[i+ptr]);
        }
        cout << ans.size() << '\n';
        for(int i=0;i<ans.size();i++)
        {
            cout << ans[i].first+1 << ' ' << ans[i].second+1 << '\n';
        }
    }    

    return 0;
}