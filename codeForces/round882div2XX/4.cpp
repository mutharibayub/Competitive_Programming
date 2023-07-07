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

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1, 0);
    }
    void update(int i, int upd)
    {
        i++;
        while(i<arr.size())
        {
            arr[i]+=upd;
            i+=i&-i;
        }
    }
    int get(int i)
    {
        i++;
        int sm = 0;
        while(i)
        {
            sm+=arr[i];
            i-=i&-i;
        }return sm;
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
        int n, m, q;
        cin>>n>>m>>q;
        string s;
        cin>>s;

        set<int> rem;
        for(int i=0;i<n;i++)rem.insert(i);
        vector<int> order;
        for(int i=0;i<m;i++)
        {
            int l, r;
            cin>>l>>r;
            l--,r--;
            auto iter = rem.lower_bound(l);
            vector<int> toErase;
            while(iter!=rem.end()&&(*iter)<=r)
            {
                toErase.push_back(*iter);
                order.push_back(*iter);
                iter++;
            }
            for(auto ele:toErase)rem.erase(ele);
        }
        int mainSize = order.size();

        for(auto ele: rem)order.push_back(ele);

        vector<int> weight(n, -1);
        for(int i=0;i<n;i++)
        {  
            weight[order[i]]=i;
        }

        FenwickTree fwt(n);
        int oneCount = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                fwt.update(weight[i], +1);
                oneCount++;
            }
        }
        for(int i=0;i<q;i++)
        {
            int idx;
            cin>>idx;
            idx--;
            if(s[idx]=='1')
            {
                s[idx]='0';
                fwt.update(weight[idx], -1);
                oneCount--;
            }
            else
            {
                s[idx]='1';
                fwt.update(weight[idx], +1);
                oneCount++;
            }
            int needCount = min(oneCount, mainSize);
            if(needCount==0)cout << 0 << '\n';
            else cout << needCount - fwt.get(needCount-1) << '\n'; 
        }
    }    

    return 0;
}