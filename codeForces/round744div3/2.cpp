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
        for(int i=0;i<n;i++)cin>>arr[i].first;
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                if(arr[j].first<arr[i].first||(arr[j].first==arr[i].first&&j<i))cnt++;
            }
            arr[i].second=cnt;
        }
        vector<array<int, 3>> ans;
        for(int i=0;i<n;i++)
        {
            int loc=-1;
            for(int j=0;j<n;j++)
            {
                if(arr[j].second==i)
                {
                    loc=j;
                    break;
                }
            }
            if(loc==arr[loc].second)continue;
            pair<int,int> tmp=arr[loc];
            ans.push_back({tmp.second, loc, loc-tmp.second});
            arr.erase(arr.begin()+loc);
            arr.insert(arr.begin()+tmp.second, tmp);
        }
        cout << ans.size() << '\n';
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j)cout << ' ';
                cout << ans[i][j]+(j<2);
            }cout << '\n';
        }
    }    

    return 0;
}