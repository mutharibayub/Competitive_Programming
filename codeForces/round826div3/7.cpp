#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <assert.h>
#include <string>

using namespace std;

void addSet(vector<int> &sets, int set)
{
    bool added=false;
    for(int i=0;i<sets.size();i++)
    {
        if((sets[i]&set)==set)return;
        if((sets[i]|set)==set)
        {
            sets[i]=set;
            added=true;
        }
    }
    if(added)
    {
        sort(sets.begin(), sets.end());
        vector<int> tmp=sets;
        sets.clear();
        for(int i=0;i<tmp.size();i++)
        {
            if(sets.empty() || sets.back()!=tmp[i])sets.push_back(tmp[i]);
        }
    }
    else
    {
        sets.push_back(set);
    }
}

int T;

int calc(vector<vector<int>> &options, int set, int index)
{
    int ans=T;
    for(;index<options.size();index++)
    {
        bool found=false;
        for(auto option:options[index])
        {
            if((set|option)>set)
            {
                ans=min(ans, calc(options, set|option, index+1));
                found=true;
            }
        }
        if(found)return ans;
    }
    while(set)
    {
        if(set&1)ans--;
        set/=2;
    }
    return ans;    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool go=false;

    int t;
    cin>>t;
    while(t--)
    {

        int n,m;
        cin>>n>>m;
        vector<vector<int>> adjList(n);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        queue<array<int,2>> q;
        vector<int> sdist(n,1e9+7);
        vector<vector<int>> invSdist(n);
        vector<bool> done(n,false);
        q.push({0, 0});

        while(!q.empty())
        {
            int top = q.front()[1];
            int dist = q.front()[0];
            sdist[top]=dist;
            invSdist[dist].push_back(top);
            done[top]=true;
            for(auto adj:adjList[top])
            {
                if(!done[adj])q.push({dist+1,adj});
            }
            while(q.size() && done[q.front()[1]])q.pop();
        }

        int f;
        cin>>f;
        vector<int> hf(f);
        vector<int> cars(n,0);
        vector<vector<int>> needCar(n);
        for(int i=0;i<f;i++)
        {
            cin>>hf[i];
            hf[i]--;
            cars[hf[i]]++;
        }
        int k;
        cin>>k;

        T=k;
        for(int i=0;i<k;i++)
        {
            int tmp;
            cin>>tmp;

            tmp--;
            cars[hf[tmp]]--;
            needCar[hf[tmp]].push_back(i);
        }

        vector<vector<int>> sets(n);
        for(int d=0;d<n;d++)
        {
            for(auto node:invSdist[d])
            {
                sets[node].push_back(0);
                if(!needCar[node].empty())
                {
                    for(auto it:needCar[node])
                    {
                        sets[node].back()|=(1<<it);
                    }
                }
                auto tmp = sets[node];
                for(auto adj:adjList[node])
                {
                    if(sdist[adj]==d-1 && !sets[adj].empty())
                    {
                        for(auto s:tmp)
                        for(auto set:sets[adj])
                        {
                            addSet(sets[node], set|s);
                        }
                    }
                }
            }
        }


        vector<vector<int>> options;
        options.reserve(n);
        for(int i=0;i<n;i++)
        {
            while(cars[i]>0 && sets[i].size())
            {
                cars[i]--;
                options.push_back(sets[i]);
                assert(sets[i].size()<=T);
            }
        }

        int ans = calc(options, 0, 0);
        cout << ans << '\n';
    }

    return 0;
}