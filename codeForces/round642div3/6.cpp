#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll getMin(vector<vector<ll>> &mat, ll initial)
{
    vector<vector<ll>> mn(mat.size(), vector<ll>(mat.front().size()));
    if(initial>mat[0][0])return -1;
    mn[0][0]=mat[0][0]-initial;
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[i].size();j++)
        {
            if(!(i||j))continue;
            ll left = j?mn[i][j-1]:-1;
            ll top = i?mn[i-1][j]:-1;
            if(left<0&&top<0)mn[i][j]=-1;
            else if(left<0)mn[i][j]=top;
            else if(top<0)mn[i][j]=left;
            else mn[i][j]=min(left, top);
            if(mn[i][j]>=0)
            {
                int dist = i+j;
                ll target = initial+dist;
                if(target>mat[i][j])mn[i][j]=-1;
                else mn[i][j]+=mat[i][j]-target;
            }
        }
    }

    return mn.back().back()<0?-1:mn.back().back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<ll>> mat(n, vector<ll>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        ll ans = 1e18+7;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int dist = i+j;
                ll initial = mat[i][j]-dist;
                ll mn = getMin(mat, initial);
                if(mn!=-1)ans = min(ans, mn);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}