#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<pair<int64_t,int64_t>> meets;
        for(auto it:meetings)
        {
            meets.emplace_back(it[0], it[1]);
        }     
        sort(meets.begin(), meets.end());
        vector<int64_t> counts(n,0);  
        priority_queue<pair<int64_t,int64_t>, vector<pair<int64_t,int64_t>>, greater<pair<int64_t,int64_t>>> occRooms;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for(int i=0;i<n;i++)
        {
            freeRooms.emplace(i);
        }
        list<pair<int64_t,int64_t>> meetsLeft;
        int64_t meetNum=0;
        int iter = 0;
        for(int64_t t=-1;meetNum<meets.size()||meetsLeft.size();)
        { 
            if(meetsLeft.empty())
            {
                t = meets[meetNum].first;
            }
            else
            {
                t = occRooms.top().first;
            }
            while(!occRooms.empty()&&occRooms.top().first<=t)
            {
                freeRooms.emplace(occRooms.top().second);
                occRooms.pop();
            }
            while(meetNum<meets.size() && meets[meetNum].first <= t)
            {
                meetsLeft.emplace_back(meets[meetNum].first, meets[meetNum].second);
                meetNum++;
            }
            while(!freeRooms.empty()&&!meetsLeft.empty())
            {
                pair<int64_t,int64_t> meet = meetsLeft.front();
                meetsLeft.pop_front();
                int freeRoom = freeRooms.top();
                freeRooms.pop();
                counts[freeRoom]++;
                // cout << freeRoom.first << " used until " << max(freeRoom.second, meet.first)+meet.second-meet.first << '\n';
                occRooms.emplace(t+meet.second-meet.first, freeRoom);
            }
        }
        // cout << "here\n";
        int64_t maxCount=-1;
        for(auto count:counts)
        {
            maxCount = max(maxCount, count);
        }
        // cout << "here1\n";
        for(int i=0;i<counts.size();i++)
        {
            if(counts[i]==maxCount)return i;
        }
        // cout << "here2\n";
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int a = 2;
    vector<vector<int>> b = {{0,10},{1,2},{12,14},{13,15}};
    cout << s.mostBooked(a,b);

    return 0;
}