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
        int n, m, k;
        cin>>n>>m>>k;
        vector<vector<bool>> grid(n, vector<bool>(m, false));
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='*')grid[i][j]=true;
            }
        }
        vector<vector<bool>> painting(n, vector<bool>(m, false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {  
                if(grid[i][j])
                {
                    int cnt = 1;
                    for(;i>=cnt&&j>=cnt&&j+cnt<m&&grid[i-cnt][j-cnt]&&grid[i-cnt][j+cnt];cnt++){}
                    cnt--;
                    if(cnt>=k)
                    {
                        painting[i][j]=true;
                        for(int l=1;l<=cnt;l++)
                        {
                            painting[i-l][j-l]=true;
                            painting[i-l][j+l]=true;
                        }
                    }
                }
            }
        }
        cout << (painting==grid?"YES":"NO") << '\n';
    }    

    return 0;
}