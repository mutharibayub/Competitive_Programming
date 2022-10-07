// copied from python solution by sarthakBhandari
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
   int parent(vector<int> &parents, int i)
   {
        vector<int> stk;
        // stk.reserve(int(3e4));
        while(parents[i]!=i)
        {
            stk.push_back(i);
            i = parents[i];
        }
        while(!stk.empty())
        {
            parents[stk.back()] = i;
            stk.pop_back();
        }
        return i;
   } 
   int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++)
        {
            if(vals[edges[i][0]] > vals[edges[i][1]])
            {
                int tmp = edges[i][0];
                edges[i][0] = edges[i][1];
                edges[i][1] = tmp;
            }
        }
        sort(edges.begin(), edges.end(), [vals](vector<int> &edge1, vector<int> &edge2){return vals[edge1[1]]<vals[edge2[1]];});
        vector<int> parents(vals.size()), size(vals.size(), 1);
        for(int i=0;i<vals.size();i++)parents[i] = i;
        int paths = vals.size();
        for(auto edge:edges)
        {
            int parent1 = parent(parents, edge[0]), parent2 = parent(parents, edge[1]);
            if(vals[parent1]==vals[parent2])
            {
                paths += size[parent1]*size[parent2];
                parents[parent1] = parent2;
                size[parent2] += size[parent1];
            }
            else if(vals[parent1] < vals[parent2])
            {
                parents[parent1] = parent2;
            }
            else
            {
                parents[parent2] = parent1;
            }
        }
        return paths;
    }
};

int main()
{
    Solution s;
    vector<int> a = {2,5,5,1,5,2,3,5,1,5};
    vector<vector<int>> b = {{0,1},{2,1},{3,2},{3,4},{3,5},{5,6},{1,7},{8,4},{9,7}}; 
    cout << s.numberOfGoodPaths(a,b) << '\n';
}