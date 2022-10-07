// copied from python solution by sarthakBhandari
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
public:
   int parent(vector<int> &parents, int i)
   {
        vector<int> stk;
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
    
        vector<array<int,3>> es(edges.size());
        for(int i=0;i<edges.size();i++)
        {
            es[i][0] = vals[edges[i][1]];
            es[i][1] = edges[i][0];
            es[i][2] = edges[i][1];
        }
        sort(es.begin(), es.end());

        vector<int> parents(vals.size()), size(vals.size(), 1);
        for(int i=0;i<vals.size();i++)parents[i] = i;
        int paths = vals.size();

        for(auto edge:es)
        {
            int parent1 = parent(parents, edge[1]), parent2 = parent(parents, edge[2]);
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
{}