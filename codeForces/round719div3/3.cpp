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

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

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
        int n;
        cin>>n;
        if(n==1)
        {
            cout << 1 << '\n';
        }
        else if(n==2)
        {
            cout << -1 << '\n';
        }
        else
        {
            vector<vector<int>> grid(n, vector<int>(n,0));
            int loc=0;
            for(int i=0;i<n*n;i++)
            {   
                if(grid[loc/n][loc%n])loc++;
                grid[loc/n][loc%n]=i+1;
                loc+=2;
                loc%=(n*n);
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(j)cout << ' ';
                    cout << grid[i][j];
                }cout << '\n';
            }
        }
    }
    return 0;
}