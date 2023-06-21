#include <iostream>
#include <vector>
#include <array>

using namespace std;

void addEdge(array<int,2> &li, int u)
{
    if(li[0]==u||li[1]==u)return;
    if(li[0]==-1)li[0]=u;
    else li[1]=u;
}

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
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i],arr[i]--;
        vector<array<int,2>> edges(n, {-1,-1});
        for(int i=0;i<n;i++)
        {
            int u=i, v=arr[i];
            addEdge(edges[u], v);
            addEdge(edges[v], u);
        }
        int circles = 0;
        int others = 0;
        vector<bool> done(n, false);
        for(int i=0;i<n;i++)
        {
            if(!done[i]&&edges[i][1]==-1)
            {
                int ptr=i;
                done[ptr]=true;
                ptr = edges[ptr][0];
                while(edges[ptr][1]!=-1)
                {
                    done[ptr]=true;
                    if(done[edges[ptr][1]])swap(edges[ptr][1], edges[ptr][0]);
                    ptr = edges[ptr][1];
                }
                done[ptr]=true;
                others++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!done[i])
            {
                int ptr = i, last = -1;
                while(!done[ptr])
                {
                    done[ptr]=true;
                    if(last==edges[ptr][1])swap(edges[ptr][1], edges[ptr][0]);
                    last = ptr;
                    ptr = edges[ptr][1];
                }
                circles++;
            }
        }
        cout << circles + bool(others) << ' ' << circles + others << '\n';
    }

    return 0;
}