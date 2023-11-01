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
        int n, q;
        cin >> n >> q;
        vector<long long> a(n), x(q);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < q; i++)
            cin >> x[i];
        vector<vector<int>> divBy(31);
        for(int i = 0; i < n; i++)
        {
            for(int j = 30; j >= 0; j--)
            {
                if(a[i]%(1<<j) == 0)
                {
                    divBy[j].push_back(i);
                    break;
                }
            }
        }
        for(int i = 0; i < q; i++)
        {
            vector<int> toAdd;
            for(int j = x[i]; j < 31; j++)
            {
                for(auto idx: divBy[j])
                    toAdd.push_back(idx);
                divBy[j].clear();
            }
            for(auto idx: toAdd)
            {
                divBy[x[i]-1].push_back(idx);
                a[idx] += (1<<(x[i]-1));
            }
        }
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << " \n"[i==n-1];
        }
    }
    return 0;
}