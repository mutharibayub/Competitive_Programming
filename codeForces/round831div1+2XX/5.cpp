#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> children(n);
    for(int i=1;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        tmp--;
        children[tmp].push_back(i);
    }

    vector<int> score(n,0);
    vector<int> heights(n,1);

    vector<array<int,2>> stk;
    
    stk.push_back({0,-1});
    while(!stk.empty())
    {
        int node = stk.back()[0];
        int parent = stk.back()[1];
        if(children[node].size())
        {
            stk.push_back({children[node].back(), node});
            children[node].pop_back();
        }
        else
        {
            score[node] = max(heights[node], score[node]);
            if(parent!=-1)
            {
                score[parent]+=score[node];
                heights[parent]=max(heights[parent], heights[node]+1);
            }
            stk.pop_back();
        }
    }
    cout << score[0] << '\n';
    return 0;
}