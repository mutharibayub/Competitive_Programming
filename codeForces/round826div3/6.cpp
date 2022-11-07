#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<array<int,3>> arr(n);
        vector<int> coords;
        coords.reserve(n*2);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
            coords.push_back(arr[i][0]);
            coords.push_back(arr[i][1]);
        }
        sort(coords.begin(), coords.end());
        vector<vector<pair<int,bool>>> switchColor(coords.size()+1); 
        unordered_map<int,int> onColors;
        onColors.reserve(n);
        for(int i=0;i<arr.size();i++)
        {
            switchColor[lower_bound(coords.begin(), coords.end(), arr[i][0])-coords.begin()].emplace_back(arr[2], true);
            switchColor[lower_bound(coords.begin(), coords.end(), arr[i][1])-coords.begin()+1].emplace_back(arr[2], false);
        }
        vector<array<int,4>> bestColor(coords.size());
        array<int, 2> lastBest1 = {-1,-1};
        array<int, 2> lastBest2 = {-1,-1};
        for(int i=0;i<coords.size();i++)
        {
            int coord = coords[i];
            if(lastBest1[0]!=-1)lastBest1[1] += coords[i]-coords[i-1];
            if(lastBest2[0]!=-1)lastBest2[1] += coords[i]-coords[i-1];
            for(auto color:switchColor[coord])
            {
                if(color.second)
                {
                    onColors[color.first]++;
                }
                else
                {
                    onColors[color.first]--;
                    if(!onColors[color.first])
                    {
                        onColors.erase(color.first);
                        lastBest2=lastBest1;
                        lastBest1={color.first, coords[i]-coords[i-1]};
                    }
                }
            }
            if(onColors.size()>=2)
            {
                bestColor[coord] = {1,0,2,0};
            }
            else if(onColors.size()==1)
            {
                bestColor[coord] = {onColors.begin()->first, 0, lastBest1[0], lastBest1[1]};
            }
            else
            {
                bestColor[coord] = {lastBest1[0], lastBest1[1], lastBest2[0], lastBest2[1]};
            }
        }
        lastBest1 = {-1,-1};
        lastBest2 = {-1,-1};
        onColors.clear();
        for(int i=coords.size()-1;i>=0;i--)
        {
            int coord = coords[i];
            if(lastBest1[0]!=-1)lastBest1[1] += coords[i+1]-coords[i];
            if(lastBest2[0]!=-1)lastBest2[1] += coords[i+1]-coords[i];
            for(auto color:switchColor[coord])
            {
                if(color.second)
                {
                    onColors[color.first]++;
                }
                else
                {
                    onColors[color.first]--;
                    if(!onColors[color.first])
                    {
                        onColors.erase(color.first);
                        lastBest2=lastBest1;
                        lastBest1={color.first, coords[i]-coords[i-1]};
                    }
                }
            }
            if(onColors.size()>=2)
            {
                bestColor[coord] = {1,0,2,0};
            }
            else if(onColors.size()==1)
            {
                bestColor[coord] = {onColors.begin()->first, 0, lastBest1[0], min(lastBest1[1],bestColor[coord][3])};
            }
            else
            {
                bestColor[coord] = {lastBest1[0], min(lastBest1[1],bestColor[coord][1]), lastBest2[0], min(lastBest2[1], bestColor[coord][3])};
            }
        }
    }

    return 0;
}
