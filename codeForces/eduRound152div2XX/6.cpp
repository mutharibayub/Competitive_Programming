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

vector<int> getMx(const vector<int> &arr, const vector<int> &selected, int bit)
{
    if(selected.size()==1)
    {
        return {1<<30, 1, selected.front(), 0};
    }
    if(selected.size()==2)
    {
        return {1<<30, 1, selected.front(), 1, selected.back()};
    }
    if(bit==-1)
    {
        int ans=0;
        vector<int> out = {ans};
        out.push_back(selected.size());
        out.insert(out.end(), selected.begin(), selected.end());
        out.push_back(0);
        return out;    
    }
    vector<int> ones, zeros;
    for(int i=0;i<selected.size();i++)
    {
        if((arr[selected[i]]>>bit)&1)ones.push_back(selected[i]);
        else zeros.push_back(selected[i]);
    }
    int ans=(1<<30);
    vector<int> group1, group2;
    if(zeros.size()<=2&&ones.size()<=2)
    {
        if(zeros.size()<2)swap(zeros, ones);
        if(ones.size()==2) // both are two
        {
            if(min(arr[ones.front()]^arr[zeros.front()], arr[ones.back()]^arr[zeros.back()])
                > min(arr[ones.front()]^arr[zeros.back()], arr[ones.back()]^arr[zeros.front()]))
                {
                    ans = min(arr[ones.front()]^arr[zeros.front()], arr[ones.back()]^arr[zeros.back()]);
                    return {ans, 2, ones.front(), zeros.front(), 2, ones.back(), zeros.back()};
                } 
            else 
            {
                ans = min(arr[ones.front()]^arr[zeros.back()], arr[ones.back()]^arr[zeros.front()]);
                return {ans, 2, ones.front(), zeros.back(), 2, ones.back(), zeros.front()};
            }
        }
        else // ones.size()==1 && zeros.size()==2
        {
            if((arr[ones.front()]^arr[zeros.front()]) > (arr[ones.front()]^arr[zeros.back()]))
            {
                ans=arr[ones.front()]^arr[zeros.front()];
                return {ans, 1, zeros.back(), 2, ones.front(), zeros.front()};
            }
            else
            {
                ans=arr[ones.front()]^arr[zeros.back()];
                return {ans, 1, zeros.front(), 2, ones.front(), zeros.back()};
            }
        }
    }
    for(auto &tarr: {ones, zeros})
    {
        if(tarr.size())
        {
            vector<int> mx = getMx(arr, tarr, bit-1);
            ans=min(ans, mx.front());
            int len1=mx[1], len2=mx[2+len1];
            group1.insert(group1.end(), mx.begin()+2, mx.begin()+2+len1);
            group2.insert(group2.end(), mx.begin()+2+len1, mx.begin()+2+len1+len2);
        }
    }
    vector<int> out = {ans};
    for(auto &tarr: {group1, group2})
    {
        out.push_back(tarr.size());
        out.insert(out.end(), tarr.begin(), tarr.end());
    }
    return out;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<int> selected(n);
        for(int i=0;i<n;i++)selected[i]=i;
        vector<int> mx=getMx(arr, selected, 30);
        string ans(n, '0');
        for(int i=0;i<mx[1];i++)
        {
            ans[mx[2+i]]++;
        }
        cout << ans << '\n';
    }
    return 0;
}