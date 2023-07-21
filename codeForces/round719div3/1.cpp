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
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<bool> done(26, false);
        bool ok = true;
        for(int i=0;i<n&&ok;i++)
        {
            if((!i||s[i]!=s[i-1])&&done[s[i]-'A'])ok=false;
            if(i==n-1||s[i]!=s[i+1])done[s[i]-'A']=true;
        }
        cout << (ok?"YES":"NO") << '\n';
    }    

    return 0;
}