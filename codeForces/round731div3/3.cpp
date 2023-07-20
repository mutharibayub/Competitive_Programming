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

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

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
        int k, n, m;
        cin>>k>>n>>m;
        vector<int> a(n), b(m);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        vector<int> ans;
        int p1=0, p2=0;
        bool ok = true;
        while(ok&&(p1<n||p2<m))
        {
            if((p2<m)&&(p1==n||a[p1]>k))
            {
                if(b[p2]==0)k++;
                else if(b[p2]>k)ok=false;
                ans.push_back(b[p2]);
                p2++;
            }
            else
            {
                if(a[p1]==0)k++;
                else if(a[p1]>k)ok=false;
                ans.push_back(a[p1]);
                p1++;
            }
        }
        if(!ok)
        {
            cout << -1 << '\n';
            continue;
        }
        for(int i=0;i<ans.size();i++)
        {
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }    

    return 0;
}