#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cout << "Case " << t << ":\n";
        int n,k=0;
        cin>>n;
        vector<vector<int>> adjList(n);
        vector<int> depth(n,0);
        while((1<<k)<n)k++;
        vector<vector<int>> up(n, vector<int>(k,-1));
        for(int i=0;i<n;i++)
        {
            int c;
            cin>>c;
            for(int j=0;j<c;j++)
            {
                int tmp;
                cin>>tmp;
                adjList[i].push_back(--tmp);
                up[tmp][0]=i;
                depth[tmp]=depth[i]+1;
            }
        }
        for(int i=1;i<k;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(up[j][i-1]!=-1)
                {
                    up[j][i] = up[up[j][i-1]][i-1];
                }
            }
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int v,w;
            cin>>v>>w;
            v--,w--;
            if(depth[v]<depth[w])swap(v,w);
            for(int jump=k-1;jump>=0&&depth[v]>depth[w];jump--)
            {
                while(depth[v]-(1<<jump)>=depth[w])
                {
                    v=up[v][jump];
                }
            }
            if(v==w)
            {
                cout << v+1 << '\n';
                continue;
            }
            for(int jump=k-1;jump>=0;jump--)
            {
                while(up[v][jump]!=up[w][jump])
                {
                    v=up[v][jump];
                    w=up[w][jump];
                }
            }
            cout << up[v][0]+1 << '\n';
        }
    }


    return 0;
}