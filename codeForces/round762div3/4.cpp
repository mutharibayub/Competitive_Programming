#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<vector<int>> &p, int target)
{
    int n=p.size(), m=p[0].size();
    vector<bool> yes(m,false);
    int yesCount = 0;
    int bestIdx = -1;
    int bestCount = 0;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(p[i][j]>=target)cnt++;
        }
        if(cnt>bestCount)
        {
            bestCount=cnt;
            bestIdx=i;
        }
    }
    if(bestCount<=1)return false;
    for(int i=0;i<m;i++)
    {
        yes[i]=p[bestIdx][i]>=target;
        yesCount+=yes[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i==bestIdx)continue;
        for(int j=0;j<m;j++)
        {
            if(p[i][j]>=target&&!yes[j])
            {
                yes[j]=true;
                yesCount+=yes[j];
            }
        }
    } 
    return yesCount==m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> p(n, vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>p[i][j];
            }
        } 
        int ans=0;
        for(int jmp=1e9+7;jmp;jmp/=2)
        {
            while(ans+jmp<1e9+7&&isPossible(p, ans+jmp))ans+=jmp;
        }
        cout << ans << '\n';
    }

    return 0;
}