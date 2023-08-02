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
    // cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<int> narr(n);
        for(int i=0;i<n;i++)cin>>narr[i];
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            if(i&&narr[i]&&narr[i-1]==narr[i])continue;
            arr.push_back(narr[i]); 
        }
        n=arr.size();
        array<vector<int>, 3> locs;
        for(int i=0;i<n;i++)
        {
            locs[arr[i]].push_back(i);
        }
        vector<bool> done(n, false);
        int cnt=0;
        for(int i=0;i<locs[2].size();i++)
        {
            if(done[locs[2][i]])continue;
            cnt++;
            for(int j=locs[2][i];j<n;j++)
            {
                if(done[j])break;
                done[j]=true;
                if(!arr[j])break;
            }
            for(int j=locs[2][i]-1;j>=0;j--)
            {
                if(done[j])break;
                done[j]=true;
                if(!arr[j])break;
            }
        }
        for(int i=0;i<locs[1].size();i++)
        {
            if(done[locs[1][i]])continue;
            done[locs[1][i]]=true;
            cnt++;
            if(locs[1][i]&&!done[locs[1][i]-1])done[locs[1][i]-1]=true;
            else if(locs[1][i]+1<n&&!done[locs[1][i]+1])done[locs[1][i]+1]=true;
        }
        for(int i=0;i<n;i++)
        {
            if(!done[i])cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}