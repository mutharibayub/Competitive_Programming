#include <iostream>
#include <vector>
#include <array>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int getIndex(vector<pair<string,int>> &cities, const string &city)
{
    int i=0;
    for(int jump=cities.size()-1;jump;jump/=2)
    {
        while(i+jump<cities.size()&&cities[i+jump].first<=city)i+=jump;
    }
    return cities[i].second;
}

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
        vector<pair<string,int>> cities;
        vector<vector<array<int,2>>> al(n);
        for(int i=0;i<n;i++)
        {
            cities.push_back({"",i});
            cin>>cities.back().first;
            int k;
            cin>>k;
            for(int j=0;j<k;j++)
            {
                int a,w;
                cin>>a>>w;
                a--;
                al[i].push_back({a,w});
                al[a].push_back({i,w});
            }
        }
        sort(cities.begin(), cities.end());
        int pc;
        cin>>pc;
        priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>> pq;
        vector<int> dist(n);
        for(int i=0;i<pc;i++)
        {
            string c1,c2;
            cin>>c1>>c2;
            int s,e;
            s=getIndex(cities, c1),e=getIndex(cities, c2);
            for(int i=0;i<n;i++)
            {
                dist[i]=1e9+7;
            }
            while(!pq.empty())pq.pop();
            dist[s]=0;
            pq.push({0,s});
            while(!pq.empty())
            {
                int top = pq.top()[1];
                pq.pop();
                if(top==e)break;
                for(int j=0;j<al[top].size();j++)
                {
                    int nr = al[top][j][0];
                    int nw = al[top][j][1];
                    if(dist[top]+nw<dist[nr])
                    {
                        dist[nr]=dist[top]+nw;
                        pq.push({dist[nr],nr});
                    }
                }
                while(dist[pq.top()[1]]>pq.top()[0])pq.pop();
            }
            cout << dist[e] << '\n';
        }
    }

    return 0;
}