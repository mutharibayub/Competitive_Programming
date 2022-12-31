#include <iostream>
#include <vector>
#include <string>

using namespace std;

void makePaths(vector<vector<int>> &al, vector<vector<int>> &paths, vector<int> &cpath, int root)
{
    cpath.push_back(root);
    if(al[root].size()==0)
    {
        paths.push_back(cpath);
    }
    else
    {
        makePaths(al,paths,cpath,al[root].front());
        for(int i=1;i<al[root].size();i++)
        {
            vector<int> p;
            makePaths(al,paths,p,al[root][i]);
        }
    }
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
        int root=-1;
        vector<vector<int>> al(n);
        for(int i=0;i<n;i++)
        {
            int u;
            cin>>u;
            u--;
            if(u!=i)al[u].push_back(i);
            else root=i;
        }
        vector<vector<int>> paths;
        vector<int> p;
        makePaths(al, paths, p, root);
        cout << paths.size() << '\n';
        for(int i=0;i<paths.size();i++)
        {
            cout << paths[i].size() << '\n';
            for(int j=0;j<paths[i].size();j++)
            {
                if(j)cout << ' ';
                cout << paths[i][j]+1;
            }cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}