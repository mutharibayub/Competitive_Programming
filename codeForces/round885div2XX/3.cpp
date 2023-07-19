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

ll getCnt(ll num1, ll num2)
{
    ll cnt=0;
    while(num1)
    {
        if(num2 && num1>=num2*3)
        {
            int subCount = (num1-num2)/num2/2;
            num1-=subCount*num2*2;
            cnt+=subCount*3;
        }
        else
        {
            cnt++;
            ll c = abs(num1-num2);
            num1=num2;
            num2=c;
        }
        cnt%=3;
    }
    return cnt;
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
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        array<int, 3> cnt = {0,0,0};
        for(int i=0;i<n;i++)
        {
            if(!a[i]&&!b[i])cnt[0]++,cnt[1]++,cnt[2]++;
            else cnt[getCnt(a[i],b[i])]++;
        }
        if(cnt[0]==n||cnt[1]==n||cnt[2]==n)
        {
            cout << "YES" << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }    

    return 0;
}