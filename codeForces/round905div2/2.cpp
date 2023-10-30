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
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(auto &ele: arr)
            cin>>ele;
        int shortest = 1e9+7;
        if(k==4)
        {
            array<int, 2> closest = {(int)1e8+7, (int)1e8+7};
            for(int i = 0; i < n; i++)
            {
                int dist = (2-arr[i]%2)%2;
                if(dist < closest[1])
                {
                    closest[1] = dist;
                    if(closest[1] < closest[0])
                        swap(closest[0], closest[1]);
                }
            }
            shortest = min(shortest, closest[0] + closest[1]);
        }
        for(int i = 0; i < n; i++)
        {
            shortest = min(shortest, (k-arr[i]%k)%k);
        }
        cout << shortest << '\n';
    }
    return 0;
}