#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;

#define tst int tttt;cin>>tttt;while(tttt--)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    tst
    {
        int n,x1,y1,x2,y2;
        cin>>n>>x1>>y1>>x2>>y2;
        x1--,x2--,y1--,y2--;
        int belt1 = min({n-x1-1, n-y1-1, x1, y1});
        int belt2 = min({n-x2-1, n-y2-1, x2, y2});
        cout << abs(belt1-belt2) << '\n';
    }

    return 0;
}