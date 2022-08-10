#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

void getDistance(const vector<int>& locs, vector<int>& assigned, int& maxDist, int cowsLeft)
{
    if(cowsLeft == 0)
    {
        int minDistLocal = INT_MAX;
        for(int i=0;i<assigned.size()-1;i++)
        {
            int dist=locs[assigned[i+1]]-locs[assigned[i]];
            minDistLocal = min(dist, minDistLocal);
        }
        maxDist = max(minDistLocal, maxDist);
        // if(minDistLocal != 255728005)
        // {
        //     return;
        // }
        // for(auto it:assigned)
        // {
        //     cout<<it<<' ';
        // }
        // cout<<": "<<minDistLocal;
        // cout<<'\n';
    }
    else
    {
        int assignmentStart = assigned.empty()?0:assigned.back()+1;
        for(int i=assignmentStart;locs.size()-i>=cowsLeft;i++)
        {
            assigned.push_back(i);
            getDistance(locs, assigned, maxDist, cowsLeft-1);
            assigned.pop_back();
        }
    }
}

void testCase1()
{
    int n,c;
    cin>>n>>c;
    vector<int> locs(n);
    for(int i=0;i<n;i++)
    {
        cin>>locs[i];
    }
    sort(locs.begin(),locs.end());

    // for(auto it:locs)
    // {
    //     cout<<it<<' ';
    // }cout<<'\n';

    vector<int> assigned;
    int maxDist = INT_MIN;
    getDistance(locs, assigned, maxDist, c);
    cout<<maxDist<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    int n;
    cin>>n;
    while(n--)
    {
        testCase1();
    }
}