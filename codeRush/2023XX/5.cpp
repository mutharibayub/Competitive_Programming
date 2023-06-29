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

    int n, m, ii, jj;
    cin>>n>>m>>ii>>jj;

    vector<string> grid(n);
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
    }

    vector<int> arr(m, 0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            arr[j] += (grid[i][j]=='!');
        }
    }

    vector<vector<int>> dpPlus(m+1, vector<int>(jj+1, 1e9+7));
    vector<vector<int>> dpMinus(m+1, vector<int>(jj+1, 1e9+7));
    dpPlus[0][0]=0;
    dpMinus[0][0]=0;

    for(int i=0;i<m;i++)
    {
        int plusCost = n-arr[i];
        int minusCost = arr[i];
        for(int j=0;j<=jj;j++)
        {
            if(j<jj)
            {
                dpPlus[i+1][j+1] = min(dpPlus[i+1][j+1], dpPlus[i][j]+plusCost);
                dpMinus[i+1][j+1] = min(dpMinus[i+1][j+1], dpMinus[i][j]+minusCost);
            }
            if(j>=ii)
            {
                dpPlus[i+1][1] = min(dpPlus[i+1][1], dpMinus[i][j]+plusCost);
                dpMinus[i+1][1] = min(dpMinus[i+1][1], dpPlus[i][j]+minusCost);
            }
        }
    }

    int ans = 1e9+7;
    for(int i=ii;i<=jj;i++)
    {
        ans = min(ans, dpPlus[m][i]);
        ans = min(ans, dpMinus[m][i]);
    }

    cout << ans << '\n';

    return 0;
}