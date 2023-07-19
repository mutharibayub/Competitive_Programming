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
        string s;
        cin>>s;
        vector<int> cnt(26, 0);
        for(int i=0;i<s.size();i++)
        {
            cnt[s[i]-'a']++;
        }
        int a=0, b=0;
        for(int i=0;i<26;i++)
        {
            if(cnt[i]>=2)a++,b++;
            else if(cnt[i]==1)
            {
                if(a>b)b++;
                else a++;
            }    
        }
        cout << min(a, b) << '\n';
    }    

    return 0;
}