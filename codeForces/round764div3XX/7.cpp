#include <iostream>
#include <vector>
#include <array>

using namespace std;

int getParent(vector<int> &parent, int i)
{
    if(parent[i]!=i)
    {
        parent[i]=getParent(parent, parent[i]);
    }
    return parent[i];
}

bool checkConnected(int n, int mask, const vector<array<int,3>> &edges)
{
    vector<int> parent(n);
    vector<int> size(n,1);
    for(int i=0;i<n;i++)parent[i]=i;
    int mergeCount=0;
    for(auto edge:edges)
    {
        if(bool(edge[2]&~mask))continue;
        int u=edge[0],v=edge[1];
        int p1 = getParent(parent, u), p2 = getParent(parent, v);
        if(p1!=p2)
        {
            if(size[p1]>size[p2])
            {
                swap(p1,p2);
                swap(u,v);
            }
            parent[p1]=p2;
            size[p2]+=size[p1];
            mergeCount++;
        }
    }
    return mergeCount==n-1;
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
        vector<array<int,3>> edges(m);
        for(int i=0;i<m;i++)
        {   
            for(int j=0;j<3;j++)cin>>edges[i][j];
            edges[i][0]--,edges[i][1]--;
        }
        int mask=INT_MAX;
        for(int i=30;i>=0;i--)
        {
            int tmpMask = mask&(~(1<<i));
            if(checkConnected(n,tmpMask,edges))
            {
                mask=tmpMask;
            }
        }
        cout << mask << '\n';
    }

    return 0;
}