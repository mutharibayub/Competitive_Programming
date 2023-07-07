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
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<int> secondArr;
        int sm = 0;
        for(int i=0;i+1<n;i++)
        {
            sm+=abs(arr[i]-arr[i+1]);
            secondArr.push_back(abs(arr[i]-arr[i+1]));
        }
        sort(secondArr.rbegin(), secondArr.rend());
        for(int i=0;i<k-1;i++)
        {
            sm-=secondArr[i];
        }
        cout << sm << '\n';
    }    

    return 0;
}