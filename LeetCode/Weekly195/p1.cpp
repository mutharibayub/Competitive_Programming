#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool isPathCrossing(string path) {
    unordered_set<string> visited;
    pair<int,int> cLoc = make_pair(0,0);
    visited.insert(to_string(cLoc.first)+"_"+to_string(cLoc.second));
    for(int i=0;path[i];i++)
    {
        if(path[i]=='N')
        {
            cLoc.first++;
        }
        else if(path[i]=='S')
        {
            cLoc.first--;
        }
        else if(path[i]=='W')
        {
            cLoc.second--;
        }
        else if(path[i]=='E')
        {
            cLoc.second++;
        }
        if(visited.count(to_string(cLoc.first)+"_"+to_string(cLoc.second))!=0)
        {
            return true;
        }
        visited.insert(to_string(cLoc.first)+"_"+to_string(cLoc.second));
    }
    return false;
}

int main()
{
    cout<<isPathCrossing("NES")<<endl;

}