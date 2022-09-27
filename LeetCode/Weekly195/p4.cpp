#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int maxVal = INT_MIN;
    priority_queue<pair<int,int>> q;
    for(int i=0;i<points.size();i++)
    {
        while(!q.empty() && points[i][0]-q.top().second>k)q.pop();
        if(!q.empty())
        {
            maxVal = max(maxVal, q.top().first+points[i][0]+points[i][1]);
        }
        q.push(make_pair(points[i][1]-points[i][0],points[i][0]));
    }
    return maxVal;
}

int main()
{
    vector<vector<int>> a({{-19,-12},{-13,-18},{-12,18},{-11,-8},{-8,2},{-7,12},{-5,16},{-3,9},{1,-7},{5,-4},{6,-20},{10,4},{16,4},{19,-9},{20,19}});
    int k=6;
    cout<<findMaxValueOfEquation(a,k);
    return 0;
}