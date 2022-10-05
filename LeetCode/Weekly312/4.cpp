#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int blockSize = 2e2;
    void updateArr(vector<int> &arr, vector<int> &maxes, int index, int val)
    {
        int blockNum = index/blockSize;
        int maxVal = -1;
        arr[index] = val;
        for(int i=blockNum*blockSize;i<arr.size()&&i<(blockNum+1)*blockSize;i++)
        {
            maxVal = max(maxVal, arr[i]);
        }
        maxes[blockNum] = maxVal;
    }
    int getMax(vector<int> &arr, vector<int> &maxes, int l, int r)
    {
        int maxVal = -1;
        for(int i=l;i<=r;)
        {
            if(i%blockSize==0 && r/blockSize > i/blockSize)
            {
                maxVal = max(maxVal, maxes[i/blockSize]);
                i+=blockSize;
            }
            else
            {
                maxVal = max(maxVal, arr[i]);
                i++;
            }
        }
        return maxVal;
    }
    int countPaths(map<int, vector<int>> &nodeIndexes, vector<int> &path, int pathLength, vector<int> &maxes)
    {
        int i=-1;
        int lastNode = path[pathLength-1];
        for(int jump=nodeIndexes[lastNode].size()-1;jump>0;jump/=2)
        {
            while(getMax(path, maxes, i+jump, pathLength-1)>path[pathLength-1])i+=jump;
        }
        i++;
        return nodeIndexes[lastNode].size()-i;
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(vals.size());
        for(int i=0;i<edges.size();i++)  
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }  

        vector<int> path(vals.size(), -1);
        int pathLength = 0;
        map<int,vector<int>> nodeIndexes;

        vector<int> maxes((vals.size()+blockSize-1)/blockSize);
        int curMax = -1;
        for(int i=0;i<maxes.size();i++)
        {
            for(int j=0;j<blockSize&i*blockSize+j<vals.size();i++)
            {
                maxes[i] = max(maxes[i], path[i*blockSize+j]);
            }
        }
        
        int edgeNode = -1;
        for(int i=0;i<adjList.size();i++)
        {
            if(adjList[i].size()==1)
            {
                edgeNode = i;
                break;
            }
        }
        
        int paths = 0;
        vector<int> stk;
        
        stk.push_back(edgeNode);
        updateArr(path, maxes, pathLength++, vals[edgeNode]);
        nodeIndexes[vals[edgeNode]].push_back(pathLength-1);
        paths += countPaths(nodeIndexes, path, pathLength, maxes);
        
        vector<bool> done(vals.size(), false);
        while(!stk.empty())
        {
            int top = stk.back();
            if(adjList[top].size())
            {
                int newNode = adjList[top].back();
                stk.push_back(newNode);
                updateArr(path, maxes, pathLength++, vals[newNode]);
                nodeIndexes[vals[newNode]].push_back(pathLength-1);
                paths += countPaths(nodeIndexes, path, pathLength, maxes);
                adjList[top].pop_back();
            }
            else
            {
                stk.pop_back();
                nodeIndexes[path[pathLength-1]].pop_back();
                updateArr(path, maxes, --pathLength, -1);
            }
        }

    }
};

int main()
{
    Solution s;
    vector<int> a = {1,3,2,1,3};
    vector<vector<int>> b = {{0,1},{0,2},{2,3},{2,4}}; 
    s.numberOfGoodPaths(a,b);
}