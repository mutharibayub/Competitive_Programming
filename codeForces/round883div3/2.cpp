#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        vector<string> grid(3);
        for(int i=0;i<3;i++)cin>>grid[i];
        string win = "DRAW";
        for(int i=0;i<3&&win.size()==4;i++)
        {
            bool horiz = true;
            bool vert = true;
            for(int j=0;j+1<3;j++)
            {
                horiz&=(grid[i][j]==grid[i][j+1]);
                vert&=(grid[j][i]==grid[j+1][i]);
            }
            if(horiz)win=grid[i][0];
            else if(vert)win=grid[0][i];
            if(win==".")win="DRAW";
        }
        if(win.size()==4)
        {
            if(grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2])win=grid[0][0];
            else if(grid[2][0]==grid[1][1]&&grid[1][1]==grid[0][2])win=grid[2][0];
        }
        if(win==".")win="DRAW";
        cout << win << '\n';
    }    

    return 0;
}