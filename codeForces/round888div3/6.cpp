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

array<int, 3> getMx(const vector<int> &arr, vector<int> selected, int bit)
{
    if(bit==-1)return {0, selected.front(), selected.back()};
    vector<int> zero, one;
    for(int i=0;i<selected.size();i++)
    {
        if(bool(arr[selected[i]]&(1<<bit)))one.push_back(selected[i]);
        else zero.push_back(selected[i]);
    }
    array<int, 3> best = {-1,-1,-1};
    if(zero.size()>=2)
    {
        array<int, 3> cur = getMx(arr, zero, bit-1);
        cur[0]+=(1<<bit);
        if(cur>best)best=cur;
    }
    if(one.size()>=2)
    {
        array<int, 3> cur = getMx(arr, one, bit-1);
        cur[0]+=(1<<bit);
        if(cur>best)best=cur;
    }
    if(best==(array<int,3>){-1,-1,-1})
    {
        array<int, 3> cur = getMx(arr, selected, bit-1);
        if(cur>best)best=cur;
    }
    return best;    
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
        vector<int> selected(n);
        for(int i=0;i<n;i++)selected[i]=i;
        array<int, 3> best = getMx(arr, selected, k-1);
        int num1=arr[best[1]], num2=arr[best[2]];
        int num3=((1<<k)-1)^num1;
        cout << best[1]+1 << ' ' << best[2]+1 << ' ' << num3 << '\n';
    }
    return 0;
}