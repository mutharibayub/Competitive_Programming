#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

bool isPossible(vector<array<int,3>> &hl, vector<array<int,3>> &vl, int l)
{
    priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>> pq;
    map<int,int> mp;
    int vInd = 0;
    for(auto hline:hl)
    {
        if(hline[2]-hline[1]<2*l)continue;
        while(vInd<vl.size()&&vl[vInd][0]+l<=hline[0])
        {
            pq.push({vl[vInd][1],vl[vInd][2]});
            mp[vl[vInd][2]]++;
            vInd++;
        }
        while(pq.size()>0&&pq.top()[0]-l<hline[0])
        {
            mp[pq.top()[1]]--;
            if(mp[pq.top()[1]]==0)mp.erase(pq.top()[1]);
            pq.pop();
        }
        int minVal = hline[1]+l;
        int maxVal = hline[2]-l;
        auto it = mp.lower_bound(minVal);
        if(it!=mp.end()&&it->first<=maxVal)return true;
    }
    return false;
}

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
        vector<array<int,3>> hl(n),vl(m);
        for(int i=0;i<n;i++)cin>>hl[i][1]>>hl[i][2]>>hl[i][0];
        for(int i=0;i<m;i++)cin>>vl[i][0]>>vl[i][1]>>vl[i][2];
        sort(hl.begin(), hl.end());
        sort(vl.begin(),vl.end());
        const int maxVal = 1e5;
        int ans=0;
        int jump=maxVal/2;
        for(;jump;jump/=2)
        {
            while(ans+jump<=maxVal/2&&isPossible(hl,vl,ans+jump))ans+=jump;
        }
        cout << ans << '\n';
    }


    return 0;
}