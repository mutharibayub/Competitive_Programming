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
vector<int> construct(vector<int> arr, int log)
{
    vector<int> newArr(arr.size());
    int xr = 0;
    for(int i=0;i<(1<<log);i++)
    {
        xr ^= arr[i%arr.size()];
    }
    for(int i=0;i<arr.size();i++)
    {
        newArr[i]=xr;
        xr^=arr[i];
        xr^=arr[(i+(1<<log))%arr.size()];
    }return newArr;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        int n, log=0;
        cin>>n;
        while((1<<log)<=n)log++;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        bool zero = true;
        for(int i=0;i<n;i++)zero&=(arr[i]==0);
        if(zero)
        {
            cout << 0 << '\n';
            continue;
        }
        int cnt = 0;
        for(int i=log;i>0;i--)
        {
            while(1)
            {
                vector<int> newArr = construct(arr, i);
                zero=true;
                for(int i=0;i<n;i++)zero&=(newArr[i]==0);
                if(zero)break;
                cnt += (1<<i)-1;
                arr=newArr;
            }
        }
        cout << cnt+1 << '\n';
    }    

    return 0;
}