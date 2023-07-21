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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        int n, t;
        cin>>n>>t;
        int k;
        vector<int> mem(n, -1);
        FenwickTree fwt(n);
        int log=0;
        while((1<<log)<n)log++;
        log--;
        for(int q=0;q<t;q++)
        {
            cin>>k;
            int loc=0;
            for(int i=log;i>=0;i--)
            {
                int len=loc+(1<<i);
                if(len>n)continue;
                if(mem[len-1]==-1)
                {
                    cout << "? 1 " << len << endl;
                    int cnt;
                    cin>>cnt;
                    mem[len-1]=len-cnt+fwt.get(len-1);
                }
                if(mem[len-1]-fwt.get(len-1)<k)loc=len;
            }      
            cout << "! " << loc+1 << endl;
            fwt.update(loc, +1);
        }
    }
    return 0;
}