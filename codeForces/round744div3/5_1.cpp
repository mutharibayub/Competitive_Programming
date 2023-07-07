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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i], arr[i]--;
        vector<int> loc(n);
        for(int i=0;i<n;i++)loc[arr[i]]=i;
        vector<bool> done(n, false);
        int ptr = 0;
        int curEnd = n-1;
        vector<int> start;
        vector<int> end;
        while(ptr<n)
        {
            start.push_back(ptr);
            done[ptr]=true;
            vector<int> tmp;
            while(curEnd>loc[ptr])
            {
                tmp.push_back(arr[curEnd]);
                done[arr[curEnd]]=true;
                curEnd--;
            }curEnd--;
            end.insert(end.end(), tmp.begin(), tmp.end());
            while(done[ptr]&&ptr<n)ptr++;
        }
        start.insert(start.end(), end.rbegin(), end.rend());
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << start[i]+1;
        }cout << '\n';
    }    

    return 0;
}