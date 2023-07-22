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

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1, 0);
    }
    int get(int idx)
    {
        idx++;
        int o=0;
        while(idx)
        {
            o+=arr[idx];
            idx-=idx&-idx;
        }return o;
    }
    void update(int idx, int update)
    {
        idx++;
        while(idx<arr.size())
        {
            arr[idx]+=update;
            idx+=idx&-idx;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int a, b, n;
        cin>>a>>b;
        n=a+b;
        string s;
        cin>>s;

        bool ok=true;

        for(int i=0;i<n/2&&ok;i++)
        {
            if(s[i]!='?'&&s[n-i-1]!='?'&&s[i]!=s[n-i-1])ok=false;
            if(s[i]=='?')swap(s[i], s[n-i-1]);
            if(s[i]=='0')a-=2,s[n-i-1]='0';
            else if(s[i]=='1')b-=2,s[n-i-1]='1';
        }
        if(!ok)
        {
            cout << -1 << '\n';
            continue;
        }
        if(n%2&&s[n/2]!='?')
        {
            if(s[n/2]=='0')a--;
            else b--;
        }
        if(a<0||b<0)
        {
            cout << -1 << '\n';
            continue;
        }
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!='?')continue;
            if(a>=2)s[i]='0', s[n-i-1]='0',a-=2;
            else s[i]='1', s[n-i-1]='1',b-=2;
        }
        if(b<0)
        {
            cout << -1 << '\n';
            continue;
        }
        if(a)s[n/2]='0';
        else if(b)s[n/2]='1';
        cout << s << '\n';
    }
    return 0;
}