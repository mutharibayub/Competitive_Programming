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
        cin>>n>>m;
        string x, s;
        cin>>x>>s;
        int bestVal = -1;
        for(int i=0;i<n;i++)
        {
            bool found = true;
            for(int j=0;j<m&&found;j++)
            {
                if(x[(i+j)%n] != s[j])
                    found = false;
            }
            if(found)
            {
                int cnt = 0, initN = n;
                while(initN-i < m)
                {
                    cnt++;
                    initN *= 2;
                }
                bestVal = cnt;
                break;
            }
                bestVal = min(bestVal, (m-i+n-1) / n);
        }
        cout << bestVal << '\n'; 
    }
    return 0;
}