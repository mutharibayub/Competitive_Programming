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
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

class FenwickTree
{
    vector<ll> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1, 0);
    }
    ll get(int idx)
    {
        idx++;
        ll o=0;
        while(idx)
        {
            o+=arr[idx];
            idx-=idx&-idx;
        }return o;
    }
    void update(int idx, ll update)
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
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        set<pair<int, int>> same;
        for(int i = 0; i < n; i++)
        {
            if(i+1 < n && s[i] == s[i+1])
                same.insert({i, i+1});
            if(i+2 < n && s[i] == s[i+2])
                same.insert({i, i+2});
        }
        FenwickTree fwt(n);
        for(int i = 0; i < n; i++)
        {
            fwt.update(i, s[i]-'a');
            if(i+1 < n)
                fwt.update(i+1, -(s[i]-'a'));
        }
        for(int i = 0; i < m; i++)
        {
            int type;
            cin>>type;
            if(type == 1)
            {
                int l, r, toAdd;
                cin>>l>>r>>toAdd;
                l--, r--;
                toAdd %= 26;
                fwt.update(l, +toAdd);
                if(r+1 < n)
                    fwt.update(r+1, -toAdd);
                auto updateEq = [&](int i, int j)
                {
                    if((fwt.get(i)%26+26)%26 == (fwt.get(j)%26+26)%26)
                        same.insert({i, j});
                    else
                        same.erase({i, j});
                };
                for(int i = max(0, l-2); i < l; i++)
                {
                    if(i+1 < n)
                        updateEq(i, i+1);
                    if(i+2 < n)
                        updateEq(i, i+2);
                }
                for(int i = min(n-1, r+2); i > r; i--)
                {
                    if(i-1 >= 0)
                        updateEq(i-1, i);
                    if(i-2 >= 0)
                        updateEq(i-2, i);
                }
            }
            else
            {
                int l, r;
                cin>>l>>r;
                l--, r--;
                auto it = same.lower_bound({l, -1});
                if(it == same.end() || it->second > r)
                {
                    cout << "YES" << '\n';
                    continue;
                }
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}