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
        string s;
        cin>>s;
        bool finalOdd = (n-k)%2;
        vector<int> cnt(26, 0);
        for(int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;
        int oddCount = 0;
        for(int i = 0; i < 26; i++)
            oddCount += cnt[i]%2;
        if(k-(abs(finalOdd-oddCount)) >= 0 && (k-(abs(finalOdd-oddCount)))%2 == 0)
        {
            cout << "YES" << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }
    return 0;
}