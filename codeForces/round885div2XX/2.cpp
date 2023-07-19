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

void addUp(array<int, 2> &best, int newVal) 
{
    if(newVal>best[1])best[1]=newVal;
    if(best[1]>best[0])swap(best[0], best[1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, k;
        cin>>n>>k;
        vector<array<int, 2>> bests(k, {-1, -1});
        vector<int> last(k, -1);
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i],arr[i]--;
        for(int i=0;i<n;i++)
        {
            addUp(bests[arr[i]], i-last[arr[i]]-1);
            last[arr[i]]=i;
        }
        for(int i=0;i<k;i++)
        {
            addUp(bests[i], n-last[i]-1);
        }
        int ans = 1e9+7;
        for(int i=0;i<k;i++)
        {
            // cout << i << ' ' << bests[i][0] << ' ' << bests[i][1] << '\n';
            ans = min(ans, max(bests[i][1], bests[i][0]/2));
        }
        cout << ans << '\n';
    }    

    return 0;
}