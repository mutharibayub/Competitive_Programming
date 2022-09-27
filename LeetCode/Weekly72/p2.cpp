#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    vector<set<int>> sets(2);
    bool skipped=false;
    bool start=false;
    for(int i=0;i<graph.size();i++)
    {
        int thisSet=-1;
        if(sets[0].count(i)!=0)
        {
            thisSet=0;
        }
        else if(sets[1].count(i)!=0)
        {
            thisSet=1;
        }
        int curSet=-1;
        for(int j=0;j<graph[i].size();j++)
        {
            if(curSet==-1)
            {
                if(sets[0].count(graph[i][j])!=0)
                {
                    curSet=0;
                    j=-1;
                }
                else if(sets[1].count(graph[i][j])!=0)
                {
                    curSet=1;
                    j=-1;
                }
            }
            else
            {
                if(sets[(curSet+1)%2].count(graph[i][j])!=0)
                {
                    return false;
                }
                else
                {
                    sets[curSet].insert(graph[i][j]);
                }
            }
        }
        if(curSet!=-1 && thisSet==curSet)return false;
        else if(curSet==-1 && thisSet==-1 && !start)
        {
            sets[0].insert(i);
            for(int j=0;j<graph[i].size();j++)
            {
                sets[1].insert(graph[i][j]);
            }
            start=true;
        }
        else if(thisSet!=curSet)
        {
            if(thisSet==-1)
            {
                sets[(curSet+1)%2].insert(i);
            }
            else
            {
                for(int j=0;j<graph[i].size();j++)
                {
                    sets[(thisSet+1)%2].insert(graph[i][j]);
                }
            }
        }
        else{skipped=true;}
        if(skipped && i+1==graph.size())
        {
            skipped=false;
            start=false;
            i=-1;
        }
    }
    return true;
}

int main()
{

    return 0;
}