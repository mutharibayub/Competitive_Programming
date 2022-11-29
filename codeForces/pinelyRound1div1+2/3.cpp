#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void calcHeight(vector<vector<int>> &subsets, vector<int> &height, int node)
{
    int count=0;
    for(auto subset:subsets[node])
    {
        if(height[subset]==-1)calcHeight(subsets, height, subset);
        count=max(count, 1+height[subset]);
    }
    height[node]=count;
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
        vector<set<int>> sets(n);
        vector<vector<int>> subsets(n);
        vector<int> height(n,-1);
        for(int i=0;i<n;i++)
        {
            sets[i].insert(i);
            string s;
            cin>>s;
            for(int j=0;j<n;j++)
            {
                if(s[j]=='1')
                {
                    subsets[j].push_back(i);
                }
            }
        }
        vector<vector<int>> invHeight(n);
        for(int i=0;i<n;i++)
        {
            if(height[i]==-1)calcHeight(subsets, height, i);
            invHeight[height[i]].push_back(i);
        }
        for(int i=1;i<n;i++)
        {
            for(auto &node:invHeight[i])
            {
                for(auto &child:subsets[node])
                {
                    for(auto &val:sets[child])
                    {
                        sets[node].insert(val);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout << sets[i].size() << ' ';
            for(auto &val:sets[i])
            {
                cout << val+1 << ' ';
            }cout << '\n';
        }
    }

    return 0;
}