#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI = true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n*n);
        for(int i=0;i<n*n;i+=2)
        {
            arr[i]=i/2+1;
        }
        for(int i=1;i<n*n;i+=2)
        {
            arr[i]=(n*n)-(i-1)/2;
        }
        vector<vector<int>> ans(n, vector<int>(n));
        int dir = 1;
        array<int,2> coord = {0,0};
        for(int i=0;i<n*n;i++)
        {
            ans[coord[0]][coord[1]]=arr[i];
            if(coord[1]+dir>=n||coord[1]+dir<0)
            {
                dir *= -1;
                coord[0]++;
            }
            else
            {
                coord[1]+=dir;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j)cout << ' ';
                cout << ans[i][j];
            }cout << '\n';
        }
    }

    return 0;
}