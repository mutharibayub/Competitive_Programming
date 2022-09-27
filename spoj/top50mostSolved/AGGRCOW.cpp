#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool checkDist(const vector<int>& locs, int cows, int dist)
{
    cows--;
    int distTillNow = 0;
    for(int i=1;i<locs.size();i++)
    {
        distTillNow += locs[i]-locs[i-1];
        if(distTillNow >= dist)
        {
            cows--;
            distTillNow = 0;
        }
    }
    return cows<=0;
}

void testCase()
{
    int n,c;
    cin>>n>>c;
    vector<int> locs(n);
    for(int i=0;i<n;i++)
    {
        cin>>locs[i];
    }
    sort(locs.begin(),locs.end());
    int minDist=0;
    for(int jump=locs.back()-locs.front();jump>0;jump/=2)
    {
        while(checkDist(locs, c, minDist+jump))minDist += jump;
    }
    cout<<minDist<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    int n;
    cin>>n;
    while(n--)
    {
        testCase();
    }
}