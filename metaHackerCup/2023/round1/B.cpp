#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

bool getVal(vector<int> &ans, int req, int left, int depth, int last)
{
    if(depth == 0)
    {
        if(req == left)
        {
            ans.push_back(left);
            return true;
        }
        return false;
    }
    int mx = min(left-depth, last);
    for(int i=mx;i>=1;i--)
    {
        if(req%i==0)
        {
            ans.push_back(i);
            if(getVal(ans, req/i, left-i, depth-1, i))
                return true;
            ans.pop_back();
        }
    }return false;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tttt;
    cin>>tttt;
    for(int ttt=1;ttt<=tttt;ttt++)
    {
        int num;
        cin>>num;
        vector<int> ans;
        bool found = false;
        for(int i=0;i<41&&!found;i++)
        {
            found = getVal(ans, num, 41, i, 1e9);
        }
        cout << "Case #" << ttt << ": ";
        if(found)
        {
            sort(ans.begin(), ans.end());
            cout << (int)ans.size() << ' ';
            for(int i=0;i<ans.size();i++)
            {
                cout << ans[i] << " \n"[i==ans.size()-1];
            }
            continue;
        }
        cout << -1 << '\n';
    }

    return 0;
}
