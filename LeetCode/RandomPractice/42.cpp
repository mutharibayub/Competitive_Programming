#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==1)return 0;
        vector<int> peaks;
        for(int i=0;i<height.size();i++)
        {
            int prevHeight = i?height[i-1]:0;
            int nextHeight = i+1<height.size()?height[i+1]:0;
            if(height[i] >= prevHeight && height[i] >= nextHeight)
            {
                peaks.push_back(i);
            }
        }
        priority_queue<array<int,2>> pq;
        for(int i=0;i<peaks.size();i++)
        {
            pq.push({height[peaks[i]], peaks[i]});
        }
        vector<array<int,2>> segments;
        int rightPeak = pq.top()[1];
        int leftPeak = pq.top()[1];
        pq.pop();
        while(!pq.empty())
        {
            int top = pq.top()[1];
            if(top < leftPeak)
            {
                segments.push_back({top, leftPeak});
                leftPeak = top;
            }
            else if(top > rightPeak)
            {
                segments.push_back({rightPeak, top});
                rightPeak = top;
            }
            pq.pop();
        }
        int totalWater = 0;
        for(int i=0;i<segments.size();i++)
        {
            int waterHeight = min(height[segments[i][0]],height[segments[i][1]]);
            for(int j=segments[i][0]+1;j<segments[i][1];j++)
            {
                totalWater += (waterHeight-height[j]>0)?waterHeight-height[j]:0;
            }
        }
        return totalWater;
    }
};

int main()
{
    Solution s;
    vector<int> heights = {4,2,0,3,2,5};
    cout << s.trap(heights) <<'\n';
}