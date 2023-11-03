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
        cin >> n;
        string s;
        cin >> s;
        vector<int> zeros;
        for(int i = 0; i < n; i++)
            if (s[i] == '0')
                zeros.push_back(i);
        long long val = 0;
        vector<long long> ans(n);
        for(int i = n - 1; i >= 0; i--)
        {
            if(zeros.empty())
                ans[n - i - 1] = -1;
            else
            {
                val += i-zeros.back();
                ans[n - i - 1] = val; 
                zeros.pop_back();
            }
        }
        for(int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i==n-1];
    }
    return 0;
}