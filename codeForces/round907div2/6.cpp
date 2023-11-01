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
    void update(int i, ll val)
    {
        i++;
        while(i < arr.size())
        {
            arr[i] += val;
            i += i&-i;
        }
    }
    ll get(int i)
    {
        i++;
        ll out = 0;
        while(i)
        {
            out += arr[i];
            i -= i&-i;
        }return out;
    }
};

const int N = 5e5+5;
FenwickTree timeSum(N);
map<int, ll> nodeSum[N]; 
vector<int> children[N];
ll val[N];

void calc(int u)
{
    for(auto [time, sm]: nodeSum[u])
    {
        timeSum.update(time, +sm);
    }
    val[u] = timeSum.get(N-1) - (u? timeSum.get(u-1): 0);
    for(auto child: children[u])
    {
        calc(child);
    }
    for(auto [time, sm]: nodeSum[u])
    {
        timeSum.update(time, -sm);
    }
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int q;
        cin >> q;
        int n = 1;
        children[0].clear();
        for(int i = 0; i < q; i++)
        {
            int t;
            cin >> t;
            if(t == 1)
            {
                int v;
                cin >> v;
                v--;
                children[v].push_back(n);
                n++;
            }
            else
            {
                int v, x;
                cin >> v >> x;
                v--;
                nodeSum[v][n-1] += x;
            }
        }
        calc(0);
        for(int i = 0; i < n; i++)
            cout << val[i] << " \n"[i==n-1];
        for(int i = 0; i < n; i++)
            children[i].clear();
        for(int i = 0; i < n; i++)
            nodeSum[i].clear();
    }
    return 0;
}