#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

void testCase()
{
    int n,m;
    cin>>n>>m;
    vector<array<int,3>> points(m);
    for(int i=0;i<m;i++)
    {
        cin>>points[i][1];
        cin>>points[i][0];
        points[i][2]=i+1;
    }
    sort(points.begin(),points.end());
    vector<array<int,3>> usedPoints(2*n);
    int64_t totalWeight=0;
    for(int i=0;i<2*n;i++)
    {
        usedPoints[i][0]=points[i][1];
        usedPoints[i][1]=points[i][0];
        usedPoints[i][2]=points[i][2];        
        totalWeight+=points[i][0];
    }
    // cout<<"___________________\n";
    sort(usedPoints.begin(),usedPoints.end());
    cout<<totalWeight<<'\n';
    for(int i=0;i<n;i++)
    {
        // cout<<"X\n";
        // cout<<usedPoints[i][0]<<" "<<usedPoints[i][1]<<'\n';
        // cout<<"X\n";
        cout<<usedPoints[i][2]<<' '<<usedPoints[2*n-i-1][2]<<'\n';
    }
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--)
    {
        testCase();
    }

    return 0;
}