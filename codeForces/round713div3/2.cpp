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
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<string> grid(n);
        for(int i=0;i<n;i++)cin>>grid[i];
        vector<array<int,2>> marked;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='*')marked.push_back({i,j});
            }
        }
        assert(marked.size()==2);
        if(marked[0][0]==marked[1][0])
        {
            grid[(marked[0][0]+1)%n][marked[0][1]]='*';
            grid[(marked[0][0]+1)%n][marked[1][1]]='*';
        }
        else if(marked[0][1]==marked[1][1])
        {
            grid[marked[0][0]][(marked[0][1]+1)%n]='*';
            grid[marked[1][0]][(marked[0][1]+1)%n]='*';
        }
        else
        {
            grid[marked[0][0]][marked[1][1]]='*';
            grid[marked[1][0]][marked[0][1]]='*';
        }
        for(int i=0;i<n;i++)
        {
            cout << grid[i] << '\n';
        }
    }
    return 0;
}