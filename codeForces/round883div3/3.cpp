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
        int n, m, h;
        cin>>n>>m>>h;
        vector<array<ll,3>> arr(n,{0,0,0});
        for(int i=0;i<n;i++)
        {
            arr[i][2]=-i;
            vector<int> tarr(m);
            for(int j=0;j<m;j++)
            {
                cin>>tarr[j];
            }
            sort(tarr.begin(), tarr.end());
            ll time = 0;
            for(int j=0;j<m;j++)
            {
                if(time+tarr[j]>h)break;
                else
                {
                    time+=tarr[j];
                    arr[i][0]++;
                    arr[i][1]+=time;
                }
            }
            arr[i][1]*=-1;
        }
        sort(arr.rbegin(), arr.rend());
        int ptr = 0;
        while(ptr<n&&arr[ptr][2]!=0)ptr++;
        cout << ptr+1 << '\n';
    }    

    return 0;
}