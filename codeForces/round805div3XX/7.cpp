#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> adjList(n);
    vector<int> parent(n,-1);
    vector<int> depth(n,0);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<int> stk;
    stk.push_back(0);
    while(stk.size())
    {
        int top = stk.back();
        stk.pop_back();
        for(auto adj:adjList[top])
        {
            if(adj!=parent[top])
            {
                stk.push_back(adj);
                parent[adj]=top;
                depth[adj]=depth[top]+1;
            }
        }
    }

    int q;
    cin>>q;
    unordered_set<int> left;
    vector<array<int,2>> oArr;
    left.reserve(n);
    for(int i=0;i<q;i++)
    {
        left.clear();
        oArr.clear();
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int tmp;
            cin>>tmp;
            tmp--;
            oArr.push_back({depth[tmp],tmp});
            left.insert(tmp);
        }
        sort(oArr.begin(), oArr.end());
        int node1 = oArr.back()[1], node2=-1;
        oArr.pop_back();
        while(oArr.size())
        {
            while(depth[node1]>oArr.back()[0])
            {
                left.erase(node1);
                node1 = parent[node1];
            }
            if(node1!=oArr.back()[1])
            {
                node2=oArr.back()[1];
                break;
            }
            oArr.pop_back();
        }
        while(node1!=-1 && node2!=-1)
        {
            left.erase(node1);
            left.erase(node2);
            node1=parent[node1];
            node2=parent[node2];
            if(node1==node2)
            {
                left.erase(node1);
                break;
            }
        }
        if(left.size()&&!oArr.empty())
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

}