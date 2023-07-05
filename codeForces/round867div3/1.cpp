#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n, t;
        cin>>n>>t;
        vector<int> dur(n), ent(n);
        for(int i=0;i<n;i++)cin>>dur[i];
        for(int i=0;i<n;i++)cin>>ent[i];
        
        int ans=-2;
        for(int i=0;i<n;i++,t--)
        {
            if(t>=dur[i])
            {
                if(ans==-2||ent[ans]<ent[i])
                {
                    ans=i;
                }
            }
        }
        cout << ans+1 << '\n';
    }
    return 0;
}