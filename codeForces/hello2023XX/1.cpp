#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll norm(ll n, ll mod=MOD)
{
    return (n%mod+mod)%mod;
}

ll pwr(ll n, ll e, ll mod = MOD)
{
    ll a=1;
    while(e)
    {
        if(e&1)
        {
            a = norm(a*n);
        }
        n=norm(n*n);
        e/=2;
    }
    return a;
}

ll gcd(ll a, ll b)
{
    if(b>a)swap(a,b);
    if(!b)return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI = true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int found = -1;
        for(int i=0;i+1<n;i++)
        {
            if(s[i]=='L'&&s[i+1]=='R')
            {
                found=i+1;
                break;
            }
            else if(s[i]=='R'&&s[i+1]=='L')
            {
                found=0;
                break;
            }
        }
        cout << (found==-1?-1:found) << '\n';
    }

    return 0;
}