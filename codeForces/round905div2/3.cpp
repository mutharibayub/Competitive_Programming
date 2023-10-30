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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto &ele: arr)
            cin>>ele;
        vector<int> left;
        vector<int> right;
        set<int> done;
        for(int i = 0; i < n; i++)
        {
            if(done.find(arr[i])==done.end())
            {
                left.push_back(i);
                done.insert(arr[i]);
            }
        }
        done.clear();
        for(int i = n-1; i >= 0; i--)
        {
            if(done.find(arr[i])==done.end())
            {
                right.push_back(i);
                done.insert(arr[i]);
            }
        }
        reverse(right.begin(), right.end());
        long long ans = 0;
        for(auto &l: left)
        {
            ans += right.end() - lower_bound(right.begin(), right.end(), l);
        }
        cout << ans << '\n';
    }
    return 0;
}