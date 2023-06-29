#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <array>

using namespace std;

int main() {

    int n;
    cin>>n;
    vector<pair<int, int>> crds(n);
    for(int i=0;i<n;i++)cin>>crds[i].first>>crds[i].second;
    vector<array<bool, 4>> check(n, {0,0,0,0});

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)continue;
            if(crds[i].first==crds[j].first)
            {
                if(crds[j].second>crds[i].second)
                {
                    check[i][0]=true;
                }
                else
                {
                    check[i][2]=true;
                }
            }
            else if(crds[i].second==crds[j].second)
            {
                if(crds[j].first>crds[i].first)
                {
                    check[i][1]=true;
                }
                else
                {
                    check[i][3]=true;
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        int tmp = 0;
        for(int j=0;j<4;j++)tmp+=check[i][j];
        if(tmp==4)cnt++;
    }

    cout << cnt << '\n';

    return 0;
}