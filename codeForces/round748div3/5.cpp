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
        int n,k;
        cin>>n>>k;
        vector<vector<int>> al(n);
        vector<int> neighbour(n);
        vector<bool> dead(n,false);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        int nodeCount = n;
        vector<int> leaves;
        for(int i=0;i<n;i++)
        {
            neighbour[i]=al[i].size();
            if(neighbour[i]<=1)
            {
                dead[i]=true;
                leaves.push_back(i);
            }
        }
        for(int i=0;i<k&&nodeCount;i++)
        {
            vector<int> tmp;
            for(int i=0;i<leaves.size();i++)
            {   
                for(auto neigh:al[leaves[i]])
                {
                    if(!neighbour[neigh]||dead[neigh])continue;
                    neighbour[neigh]--;
                    if(neighbour[neigh]<=1)
                    {
                        dead[neigh]=true;
                        tmp.push_back(neigh);
                    }
                }
                nodeCount--;
            }
            leaves=tmp;
        }
        cout << nodeCount << '\n';
    }

    return 0;
}