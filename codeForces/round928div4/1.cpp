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
#include <string>

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
        string s;
        cin >> s;
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            count += s[i] == 'A'? 1: -1;
        }
        cout << (count > 0? 'A': 'B') << '\n';
    }
    return 0;
}