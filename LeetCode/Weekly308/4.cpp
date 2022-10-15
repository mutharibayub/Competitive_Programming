#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <array>

using namespace std;

class Solution {
public:
    bool hasCycle(vector<vector<int>> adjList, int n)
    {
        vector<int> arm;
        vector<bool> inArm(n, false);
        for(int start=0;start<n;start++)
        {
            arm.push_back(start);
            inArm[start]=true;
            while(arm.size())
            {
                int parent = arm.back();
                if(adjList[parent].size())
                {
                    int child = adjList[parent].back();
                    if(inArm[child])return true;
                    arm.push_back(child);
                    inArm[child]=true;
                    adjList[parent].pop_back();
                }
                else
                {
                    inArm[arm.back()]=false;
                    arm.pop_back();
                }
            }
        }
        return false;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adjList1(k), adjList2(k);
        unordered_set<int> tmp;
        for(auto it:rowConditions)
        {
            tmp.insert((it[0]-1)*400+it[1]-1);
        }
        for(auto it:tmp)
        {
            adjList1[it/400].push_back(it%400);
        }
        tmp.clear();
        for(auto it:colConditions)
        {
            tmp.insert((it[0]-1)*400+it[1]-1);
        }
        for(auto it:tmp)
        {
            adjList2[it/400].push_back(it%400);
        }
        vector<array<int,2>> coords(k);
        for(int c=0;c<2;c++)
        {
            auto &adjList = c?adjList2:adjList1;
            if(hasCycle(adjList, k))return vector<vector<int>>();
            
            vector<array<int,2>> weights(k);
            for(int i=0;i<k;i++)weights[i]={0,i};
            
            for(int i=0;i<k;i++)
            {
                vector<array<int,2>> stk;
                stk.push_back({i,i});                
                while(!stk.empty())
                {
                    int node = stk.back()[0];
                    int parent = stk.back()[1];
                    if(weights[node][0] || adjList[node].empty())
                    {
                        if(node!=parent)weights[parent][0] = max(weights[parent][0], weights[node][0]+1);
                        stk.pop_back();    
                        continue;
                    }
                    for(auto child:adjList[node])
                    {
                        stk.push_back({child, node});
                    }
                }
            }
            sort(weights.rbegin(), weights.rend());
            for(int i=0;i<k;i++)
            {
                coords[weights[i][1]][c] = i;
            }
        }
        vector<vector<int>> ans(k, vector<int>(k,0));
        for(int i=0;i<k;i++)
        {
            ans[coords[i][0]][coords[i][1]] = i+1;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}