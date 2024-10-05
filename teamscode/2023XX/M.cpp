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

const int N = 1e5 + 5;

vector<int> stk[4*N];
int treeVal[4*N];
int treeL[4*N];
int treeR[4*N];
int init[N];
bool removed[N];

void reset(int i, int l, int r)
{
    stk[i].clear();
    if (l == r)
    {
        treeL[i] = treeR[i] = l;
        treeVal[i] = init[l];
        removed[l] = false;
        return;
    }
    reset(i*2+1, l, (l+r)/2);
    reset(i*2+2, (l+r)/2 + 1, r);
    treeL[i] = l;
    treeR[i] = r;
    treeVal[i] = -1;
}

int query(int i, int l, int r)
{
    if (l > treeR[i] || r < treeL[i]) return -1;
    else if(treeL[i] >= l && treeR[i] <= r) return treeVal[i];
    return max({query(i*2+1, l, r), query(i*2+2, l, r), stk[i].empty()? -1: stk[i].back()});
}

void update(int i, int l, int r, bool add, int val)
{
    if (l > treeR[i] || r < treeL[i])
        return;
    else if(treeL[i] >= l && treeR[i] <= r)
    {
        if(add)
            stk[i].push_back(val);
        else
            while(!stk[i].empty() && removed[stk[i].back()])
                stk[i].pop_back();
        treeVal[i] = stk[i].empty()? -1: stk[i].back();
        if(treeL[i] != treeR[i])
            treeVal[i] = max({treeVal[i], treeVal[i*2+1], treeVal[i*2+2]});
        return;
    }
    update(i*2+1, l, r, add, val);
    update(i*2+2, l, r, add, val);
    treeVal[i]=max({stk[i].empty()? -1: stk[i].back(), treeVal[i*2+1], treeVal[i*2+2]});
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < N; i++)
        init[i] = -1;

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        reset(0, 0, N-1);

        long long sum = 0;

        int n;
        cin>>n;
        vector<array<int, 4>> coords(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 4; j++)
                cin >> coords[i][j], coords[i][j] -= (j>1);
            int nxt = query(0, coords[i][1], coords[i][3]);
            while(nxt != -1 && coords[nxt][2] >= coords[i][0])
            {
                removed[nxt] = true;
                update(0, coords[nxt][1], coords[nxt][3], 0, 0);
                sum -= 1ll*(coords[nxt][2]-coords[nxt][0]+1)*(coords[nxt][3]-coords[nxt][1]+1);
                coords[i][0]=min(coords[i][0], coords[nxt][0]);
                coords[i][1]=min(coords[i][1], coords[nxt][1]);
                coords[i][2]=max(coords[i][2], coords[nxt][2]);
                coords[i][3]=max(coords[i][3], coords[nxt][3]);
                nxt = query(0, coords[i][1], coords[i][3]);
            }
            update(0, coords[i][1], coords[i][3], 1, i);
            sum += 1ll*(coords[i][2]-coords[i][0]+1)*(coords[i][3]-coords[i][1]+1);
            cout << sum << '\n';
        }
    }
    return 0;
}