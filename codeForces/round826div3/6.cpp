#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

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
        vector<array<int,4>> data(n);
        vector<int> dists(n,1e9+7);

        for(int i=0;i<n;i++)
        {
            cin>>data[i][0]>>data[i][1]>>data[i][2];
            data[i][2]--;
            data[i][3]=i;
        }

        vector<array<int,2>> bestSegs;
        sort(data.begin(), data.end());
        for(int i=0;i<n;i++)
        {  
            for(int j=0;j<bestSegs.size();j++)
            {
                auto seg = bestSegs[j];
                if(seg[1]!=data[i][2])
                {
                    int dist = max(data[i][0]-seg[0], 0);
                    dists[data[i][3]]=min(dists[data[i][3]], dist);
                    break;
                }
            }
            bool added=false;
            if(bestSegs.size())
            {
                if(bestSegs[0][1]==data[i][2])
                {
                    added=true;
                    if(bestSegs[0][0]<data[i][1])
                    {
                        bestSegs[0][0]=data[i][1];
                        added=true;
                    }
                }
                else if(bestSegs.size()>1 && bestSegs[1][1]==data[i][2])
                {
                    added=true;
                    if(bestSegs[1][0]<data[i][1])
                    {
                        bestSegs[1][0]=data[i][1];
                    }
                }
            }
            if(!added)
            {
                bestSegs.push_back({data[i][1], data[i][2]});
            }
            sort(bestSegs.rbegin(), bestSegs.rend());
            if(bestSegs.size()==3)bestSegs.pop_back();
            swap(data[i][0], data[i][1]);
            data[i][0]*=-1;
            data[i][1]*=-1;
        }

        bestSegs.clear();
        sort(data.begin(), data.end());
        for(int i=0;i<n;i++)
        {  
            for(int j=0;j<bestSegs.size();j++)
            {
                auto seg = bestSegs[j];
                if(seg[1]!=data[i][2])
                {
                    int dist = max(data[i][0]-seg[0], 0);
                    dists[data[i][3]]=min(dists[data[i][3]], dist);
                    break;
                }
            }
            bool added=false;
            if(bestSegs.size())
            {
                if(bestSegs[0][1]==data[i][2])
                {
                    added=true;
                    if(bestSegs[0][0]<data[i][1])
                    {
                        bestSegs[0][0]=data[i][1];
                        added=true;
                    }
                }
                else if(bestSegs.size()>1 && bestSegs[1][1]==data[i][2])
                {
                    added=true;
                    if(bestSegs[1][0]<data[i][1])
                    {
                        bestSegs[1][0]=data[i][1];
                    }
                }
            }
            if(!added)
            {
                bestSegs.push_back({data[i][1], data[i][2]});
            }
            sort(bestSegs.rbegin(), bestSegs.rend());
            if(bestSegs.size()==3)bestSegs.pop_back();
            swap(data[i][0], data[i][1]);
            data[i][0]*=-1;
            data[i][1]*=-1;
        }

        vector<vector<int>> onPoints(2*n);
        vector<int> cc;
        set<int> curOn;
        vector<int> onColCount(n,0);
        int distinctOn = 0;
        for(int i=0;i<n;i++)
        {
            cc.push_back(data[i][0]);
            cc.push_back(data[i][1]);
        }
        sort(cc.begin(), cc.end());
        for(int i=0;i<n;i++)
        {
            onPoints[lower_bound(cc.begin(), cc.end(), data[i][0])-cc.begin()].push_back(i);
            onPoints[lower_bound(cc.begin(), cc.end(), data[i][1])-cc.begin()].push_back(i-n);
        }

        for(auto arr:onPoints)
        {
            sort(arr.rbegin(), arr.rend());
            for(auto ele:arr)
            {
                if(ele>=0)
                {   
                    if(++onColCount[data[ele][2]] == 1)
                    {
                        distinctOn++;
                    }
                    curOn.insert(ele);
                    if(distinctOn>1)
                    {
                        for(auto it:curOn)
                        {
                            dists[data[it][3]]=0;
                        }
                        curOn.clear();
                    }
                }
                else
                {
                    ele+=n;
                    if(--onColCount[data[ele][2]]==0)
                    {
                        distinctOn--;
                    }
                    curOn.erase(ele);
                }
            }
        }


        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << dists[i];
        }cout << '\n';


    }

    return 0;
}
