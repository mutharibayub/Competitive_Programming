#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_VAL = 26*26;

template<typename T>
int getIndex(vector<T> &arr, T val)
{
    return lower_bound(arr.begin(), arr.end(), val)-arr.begin();
}

int main()
{
    string filename = "16input.txt";
    ifstream fin(filename);

    map<string,map<string,int>> dist;
    set<string> allNodes;
    map<string,int> pr;
    while(!fin.eof())
    {
        string tmp;
        fin>>tmp>>tmp;
        if(tmp=="")break;
        string node = tmp;
        allNodes.insert(node);
        fin>>tmp>>tmp>>tmp;
        tmp.pop_back();
        reverse(tmp.begin(),tmp.end());
        for(int i=0;i<5;i++)tmp.pop_back();
        reverse(tmp.begin(),tmp.end());
        pr[node]=stoi(tmp);
        fin>>tmp>>tmp>>tmp>>tmp;
        while(1)
        {
            bool end=true;
            fin>>tmp;
            if(tmp.back()==',')
            {
                end=false;
                tmp.pop_back();
            }
            dist[node][tmp]=1;
            if(end)break;
        }
    }

    for(auto k:allNodes)
    {   
        for(auto i:allNodes)
        {
            for(auto j:allNodes)
            { 
                if(dist[i].find(k)==dist[i].end()||dist[k].find(j)==dist[k].end())continue;
                if(dist[i].find(j)==dist[i].end())
                {
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
                else
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
                
            }
        }
    }

    vector<string> fNodes;
    for(auto node: allNodes)
    {        
        if(pr[node]==0&&node!="AA")
        {
            dist.erase(node);
        }
        else
        {
            fNodes.push_back(node);
        }
    }
    for(auto &it:dist)
    {
        for(auto node:allNodes)
        {
            if(pr[node]==0&&node!="AA")
            {
                it.second.erase(node);
            }
        }
    }

    sort(fNodes.begin(), fNodes.end());
    map<array<ll, 5>, ll> dps[27]; // curTime1, curNode1, curTime2, curNode2, set

    ll ans=0;
    dps[1][{26, 0, 26, 0, 1}]=0;
    for(int i=1;i<=26;i+=1)
    {  
        auto tmpDp = dps[i];
        for(auto ele:tmpDp)
        {
            string nodeName = fNodes[ele.first[1]];
            ll sett = ele.first[4];
            // if(__builtin_popcountll(sett)!=i)continue;
            ll timeLeft = ele.first[0];
            ll val = ele.second;
            for(auto neigh:dist[nodeName])
            {
                int ind = getIndex(fNodes, neigh.first);
                int dist = neigh.second;
                if(sett&(1<<ind))continue;
                if(timeLeft-1-dist<=0)continue;
                ll nval = val+(timeLeft-1-dist)*pr[neigh.first];
                ans = max(ans, nval);
                dps[i+1][{timeLeft-1-dist,ind,ele.first[2],ele.first[3],sett|(1<<ind)}]=max(dps[i+1][{timeLeft-1-dist,ind,ele.first[2],ele.first[3],sett|(1<<ind)}], nval);
            }
            nodeName = fNodes[ele.first[3]];
            timeLeft = ele.first[2];
            for(auto neigh:dist[nodeName])
            {
                int ind = getIndex(fNodes, neigh.first);
                int dist = neigh.second;
                if(sett&(1<<ind))continue;
                if(timeLeft-1-dist<=0)continue;
                ll nval = val+(timeLeft-1-dist)*pr[neigh.first];
                ans = max(ans, nval);
                dps[i+1][{ele.first[0],ele.first[1],timeLeft-1-dist,ind,sett|(1<<ind)}]=max(dps[i+1][{ele.first[0],ele.first[1],timeLeft-1-dist,ind,sett|(1<<ind)}], nval);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}