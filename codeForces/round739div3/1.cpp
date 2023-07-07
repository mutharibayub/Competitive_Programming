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

    vector<int> arr = {0};
    for(int i=1;arr.size()<=1000;i++)
    {
        if(i%10==3||i%3==0)continue;
        arr.push_back(i);
    }

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int k;
        cin>>k;
        cout << arr[k] << '\n';
    }    

    return 0;
}