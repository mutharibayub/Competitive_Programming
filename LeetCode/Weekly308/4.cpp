#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <array>

using namespace std;

class Solution {
public:
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
        tmp.clear();
        
        vector<array<int,2>> coords(k);
        vector<bool> inArm(k, false);
        
        for(int c=0;c<2;c++)
        {
            auto &adjList = c?adjList2:adjList1;
            
            vector<array<int,2>> weights(k);
            for(int i=0;i<k;i++)weights[i]={0,i};
            
            for(int i=0;i<k;i++)
            {
                vector<int> stk;
                inArm[i]=true;
                stk.push_back(i);                
                while(!stk.empty())
                {
                    int node = stk.back();
                    if(adjList[node].size())
                    {
                        if(inArm[adjList[node].back()])return vector<vector<int>>();
                        stk.push_back(adjList[node].back());
                        inArm[adjList[node].back()]=true;
                        adjList[node].pop_back();
                    }
                    else
                    {
                        int w = weights[stk.back()][0];
                        inArm[stk.back()]=false;
                        stk.pop_back();
                        if(stk.size())weights[stk.back()][0] = max(weights[stk.back()][0], w+1);
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