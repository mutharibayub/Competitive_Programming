#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph
{
    int n;
    vector<list<pair<int,int>>> adjList;
public:
    Graph(int n):n(n)
    {
        adjList.resize(n);
    }
    void addNode(int src, int dest, int weight)
    {
        adjList[src].push_back(make_pair(dest,weight));
    }
    int shortestPath(int src, int dest, int k)
    {
        vector<unordered_map<int,int>> dist(k+2); //index k saves k-1 step min distances
        dist[0].insert(make_pair(src,0));
        for(int i=1;i<=k+1;i++)
        {
            for(auto iter:dist[i-1])
            {
                for(auto neighbour:adjList[iter.first])
                {
                    if(dist[i].find(neighbour.first)!=dist[i].end())
                    {
                        dist[i][neighbour.first]=min(dist[i][neighbour.first],iter.second+neighbour.second);
                    }
                    else
                    {
                        dist[i][neighbour.first]=iter.second+neighbour.second;
                    }
                }
            }
        }
        // for(int i=0;i<=k+1;i++)
        // {
        //     for(auto iter:dist[i])
        //     {
        //         cout<<iter.first<<"x"<<iter.second<<"\t";
        //     }
        //     cout<<"\n";
        // }
        int minDist = INT_MAX;
        for(int i=0;i<=k+1;i++)
        {
            if(dist[i].find(dest)!=dist[i].end())
            {
                minDist = min(minDist,dist[i][dest]);
            }
        }
        return minDist==INT_MAX?-1:minDist;
    }
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    Graph g(n);
    for(int i=0;i<flights.size();i++)
    {
        g.addNode(flights[i][0],flights[i][1],flights[i][2]);
    }
    return g.shortestPath(src,dst,k);
}

int main()
{

    return 0;
}