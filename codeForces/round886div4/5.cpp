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


ll getSm(vector<int> &arr, ll w)
{
    ll sm=0;
    for(int i=0;i<arr.size();i++)
    {
        if(ll(1e18)/(2*w+arr[i]) < 2*w+arr[i])return 1e18+1;
        ll toAdd = (2*w+arr[i])*(2*w+arr[i]);
        if(sm+toAdd>1e18)return 1e18+1;
        sm+=toAdd;
    }
    return sm;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        ll n, c;
        cin>>n>>c;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        ll cur=0;
        for(ll jmp=1e9;jmp;jmp/=2)
        {
            while(cur+jmp<1e18&&getSm(arr, cur+jmp)<=c)cur+=jmp;
        }
        cout << cur << '\n';
    }
    return 0;
}