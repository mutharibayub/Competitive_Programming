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

    map<int, int> sqrt;
    for(int i=1;i*i<=1e9;i++)
    {
        sqrt[i*i]=i;
    }

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int k;
        cin>>k;
        pair<int,int> sq = *prev(sqrt.lower_bound(k+1));
        k-=sq.first;
        int row=1, col=sq.second+1;
        if(!k)
        {
            cout << sq.second << ' ' << 1 << '\n';
            continue;
        }
        if(k>=sq.second+1)
        {
            row+=sq.second;
            col-=(k-sq.second-1);
        }
        else
        {
            row+=k-1;
        }
        cout << row << ' ' << col << '\n';
    }    

    return 0;
}