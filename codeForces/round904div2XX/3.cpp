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

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> rngs(n);
        vector<int> indexes = {1, m};
        for(int i = 0; i < n; i++)
        {
            cin >> rngs[i].first >> rngs[i].second;
            indexes.push_back(rngs[i].first);
            indexes.push_back(rngs[i].second);
        }
        sort(indexes.begin(), indexes.end());
        vector<int> sm1(indexes.size(), 0), sm2(indexes.size(), 0);
        for(int i = 0; i < rngs.size(); i++)
        {
            int start = lower_bound(indexes.begin(), indexes.end(), rngs[i].first) - indexes.begin();
            int end = lower_bound(indexes.begin(), indexes.end(), rngs[i].second+1) - indexes.begin();
            if(rngs[i].first > 1)
            {
                sm1[start] += +1;
                if (end < indexes.size())
                    sm1[end] += -1;
            }
            if(rngs[i].second < m)
            {
                sm2[start] += +1;
                if (end < indexes.size())
                    sm2[end] += -1;
            }
        }
        int mx = 0;
        int smm1 = 0, smm2 = 0;
        for(int i = 0; i < indexes.size(); i++)
        {
            smm1 += sm1[i];
            smm2 += sm2[i];
            mx = max({mx, smm1, smm2});
        }
        cout << mx << '\n';
    }   
    return 0;
}