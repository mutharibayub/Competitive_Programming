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

const int inf = 1e9+7;

int doOp(vector<int> &arr, int val)
{
    int idx = 0;
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] == val)
        {
            idx = i;
            break;
        }
    }
    vector<int> nxt;
    nxt.insert(nxt.end(), arr.begin()+idx+1, arr.end());
    nxt.push_back(val);
    nxt.insert(nxt.end(), arr.begin(), arr.begin()+idx);
    arr = nxt;
    return idx;
}

int main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        int len[2];
        cin >> len[0] >> len[1];
        vector<int> arr[2];
        for(int j = 0; j < 2; j++)
        {
            arr[j] = vector<int>(len[j]+1);
            arr[j][0] = len[j];
            for(int i = 1; i <= len[j]; i++)
                cin >> arr[j][i], arr[j][i]--;
        }
        int mn[2][2] = {{inf, inf}, {inf, inf}};
        vector<int> shortestPath[2][2];
        for(int iter = 0; iter < 2; iter++)
        {
            vector<int> &a = arr[iter];
            int n = len[iter]; 
            for(int i = 0; i <= n; i++)
            {
                vector<int> sec(n+1);
                for(int k = 0; k <= n; k++)
                {
                    sec[a[(i+k)%(n+1)]] = k;
                }
                vector<int> vis(n+1, 0);
                int steps = 0;
                vector<int> path;
                vector<int> main;
                for(int j = 0; j < n+1; j++)
                {
                    if(vis[j])
                        continue;
                    vector<int> pathToAdd;
                    int cycleLen = 0;
                    bool mainCycle = 0;
                    int ptr = j;
                    while(!vis[ptr])
                    {
                        if (ptr == n)
                            mainCycle = 1;
                        vis[ptr] = 1;
                        ptr = sec[ptr];
                        cycleLen++;
                        pathToAdd.push_back(ptr);
                    }
                    if (cycleLen > 1)
                    {
                        if (mainCycle)
                        {
                            int start = -1;
                            for(int k = 0; k < pathToAdd.size(); k++)
                            {
                                if(pathToAdd[k] == n)
                                {
                                    start = k+1;
                                    break;
                                }
                            }
                            for(int k = 0; k < pathToAdd.size()-1; k++, start=(start+1)%pathToAdd.size())
                            {
                                main.push_back(pathToAdd[start]);
                            }
                        }
                        else
                        {
                            path.insert(path.end(), pathToAdd.begin(), pathToAdd.end());
                            path.push_back(pathToAdd.front());
                        }
                    }
                }
                path.insert(path.begin(), main.begin(), main.end());
                steps = path.size();
                if (steps < mn[iter][steps%2])
                {
                    mn[iter][steps%2] = steps;
                    shortestPath[iter][steps%2] = path;
                }
            }
        }
        int ans = min(max(mn[0][0], mn[1][0]), max(mn[0][1], mn[1][1]));
        if (ans == inf)
        {
            cout << -1 << '\n';
            continue;
        }
        int par = (ans == max(mn[0][0], mn[1][0])? 0: 1);
        for(int iter = 0; iter < 2; iter++)
            while(shortestPath[iter][par].size() < ans)
                shortestPath[iter][par].push_back(0);
        arr[0].erase(arr[0].begin());
        arr[1].erase(arr[1].begin());
        cout << ans << '\n';
        for(int i = 0; i < ans; i++)
        {
            cout << doOp(arr[0], shortestPath[0][par][i]) + 1 << ' ';
            cout << doOp(arr[1], shortestPath[1][par][i]) + 1 << '\n';
        }
    }
    return 0;
}