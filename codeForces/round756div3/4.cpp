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
        int n;
        cin>>n;
        vector<int> parent(n);
        vector<int> perm(n);
        vector<int> dist(n,-1);
        vector<int> weight(n,-1);
        int root = -1;
        for(int i=0;i<n;i++)
        {
            cin>>parent[i];
            if(--parent[i]==i)root=i;
        }
        for(int i=0;i<n;i++)
        {
            cin>>perm[i];
            perm[i]--;
        }
        int nxt = 0;
        bool ok = true;
        for(int i=0;i<n&&ok;i++)
        {
            int u = perm[i];
            if(u!=root&&dist[parent[u]]==-1)
            {
                ok=false;
            }
            else
            {
                dist[u]=nxt++;
                weight[u]=dist[u]-dist[parent[u]];
            }
        }
        if(ok)
        {
            for(int i=0;i<n;i++)
            {
                if(i)cout << ' ';
                cout << weight[i];
            }cout << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }

    return 0;
}