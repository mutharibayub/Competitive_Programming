#include <iostream>
#include <vector>
#include <list>

using namespace std;

void testCase(int n)
{
    int v,e;
    cin>>v>>e;
    vector<list<int>> adjList(v);
    vector<int> color(v,1);
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adjList[a-1].push_back(b-1);
        adjList[b-1].push_back(a-1);
    }
    for(int i=0;i<v;i++)
    {
        for(auto it:adjList[i])
        {
            if(color[i] == color[it])
            {
                color[it] = color[i]+1;
            }
            if(color[it]>2)
            {
                cout << "Scenario #"<<n<<":\nSuspicious bugs found!\n";
                return;
            }
        }
    }
    cout << "Scenario #"<<n<<":\nNo suspicious bugs found!\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        testCase(i+1);
    }

    return 0;
}