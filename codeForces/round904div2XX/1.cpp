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
        int x, k;
        cin >> x >> k;
        for(; ; x++)
        {
            int digitSum = 0, tmp = x;
            while(tmp)
            {
                digitSum += tmp%10;
                tmp /= 10;
            }
            if(digitSum % k == 0)
                break;
        }
        cout << x << '\n';
    }
    return 0;
}