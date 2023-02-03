#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,d;
        cin>>n>>m>>d;
        vector<int> loc(n);
        vector<int> a(m);
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            loc[--num]=i;
        }
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
            --a[i];
        }
        int ans=1e9+7;
        for(int i=0;i+1<m&&ans;i++)
        {
            int pos1=loc[a[i]], pos2=loc[a[i+1]];
            ans=min(ans, pos2<=pos1?0:pos2-pos1);
            if(d<n-1&&ans)ans=min(ans, max(0,d+1-(pos2-pos1)));
        }
        cout << ans << '\n';
    }

    return 0;
}