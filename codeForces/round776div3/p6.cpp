#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<ll> arr(n);
        vector<vector<array<int,3>>> opts(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<m;i++)
        {
            array<int,3> opt;
            int task;
            for(int j=0;j<3;j++)
            {
                if(!j)cin>>task;
                else cin>>opt[j-1];
            }
            opt[2]=i;
            opts[--task].push_back(opt);
        }
        vector<vector<array<ll,101>>> bestTime(n);
        vector<vector<array<int,101>>> parent(n);
        for(int i=0;i<n;i++)
        {
            bestTime[i].resize(opts[i].size());
            parent[i].resize(opts[i].size());   
            for(int j=0;j<opts[i].size();j++)
            {
                for(int k=0;k<101;k++)
                {
                    bestTime[i][j][k]=1e15;
                    parent[i][j][k]=k;
                }
            }
            if(opts[i].size())bestTime[i][0][0]=0;
        }
        for(int job=0;job<n;job++)
        {
            for(int trn=0;trn<opts[job].size();trn++)
            {
                if(trn)
                {
                    bestTime[job][trn]=bestTime[job][trn-1];
                    for(int i=0;i<100;i++)
                    {
                        if(bestTime[job][trn-1][i]==1e15)continue;
                        int newPerc = min(100,i+opts[job][trn][1]);
                        ll newTime = bestTime[job][trn-1][i]+opts[job][trn][0];
                        if(newTime<bestTime[job][trn][newPerc])
                        {
                            bestTime[job][trn][newPerc]=newTime;
                            parent[job][trn][newPerc]=i;
                        }                    
                    }
                }
                else
                {
                    bestTime[job][trn][opts[job][trn][1]]=opts[job][trn][0];
                    parent[job][trn][opts[job][trn][1]]=0;
                }
            }
        }
        vector<ll> bestTimes(n,1e15);
        vector<int> bestIdx(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<opts[i].size();j++)
            {
                if(bestTime[i][j][100]<bestTimes[i])
                {
                    bestTimes[i]=bestTime[i][j][100];
                    bestIdx[i]=j;
                }
            }
        }
        bool isPossible = true;
        ll time=0;
        for(int i=0;i<n&&isPossible;i++)
        {
            time+=bestTimes[i];
            if(time>arr[i])
            {
                isPossible=false;
            }
        }
        if(!isPossible)
        {
            cout << -1 << '\n';
            continue;
        }
        vector<int> tasks;
        for(int i=n-1;i>=0;i--)
        {
            int cur = 100;
            for(int j=bestIdx[i];j>=0;j--)
            {
                if(parent[i][j][cur]!=cur)
                {
                    cur=parent[i][j][cur];
                    tasks.push_back(opts[i][j][2]);
                }
            }            
        }
        reverse(tasks.begin(), tasks.end());
        cout << tasks.size() << '\n';
        for(int i=0;i<tasks.size();i++)
        {
            if(i)cout << ' ';
            cout << tasks[i]+1;
        }cout << '\n';
    }
}