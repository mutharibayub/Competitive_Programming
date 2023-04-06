#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

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
        vector<int> aa(n),bb(n);
        vector<vector<int>> inds(n);
        vector<vector<int>> nxt(n);
        for(int i=0;i<n;i++)cin>>aa[i],--aa[i];
        for(int i=0;i<n;i++)cin>>bb[i],--bb[i];
        bool ok = true;
        for(int i=0;i<n&&ok;i++)
        {
            inds[aa[i]].push_back(i);
            if(inds[aa[i]].size()>2)ok=false;
            inds[bb[i]].push_back(i);
            if(inds[bb[i]].size()>2)ok=false;
        }
        if(!ok)
        { 
            cout << -1 << '\n';
            continue;
        }
        vector<int> ansInds;
        vector<int> done(n, false);
        for(int i=0;i<n;i++)
        {
            int start=i, val=aa[start];
            vector<int> path;
            while(!done[start])
            {
                int nxtInd=inds[val][0]==start?inds[val][1]:inds[val][0];
                val=aa[nxtInd]==val?bb[nxtInd]:aa[nxtInd];
                path.push_back(start);
                done[start]=true;
                start=nxtInd;
            }
            if(path.size()<=1)continue;
            array<array<int,2>,2> dp;
            dp[0][0]=dp[1][1]=0;
            dp[1][0]=dp[0][1]=-1;
            for(int j=0;j<path.size();j++)
            {
                int cur = path[j], nxt = path[(j+1)%path.size()];
                int same = aa[cur]==aa[nxt]||bb[cur]==bb[nxt];
                array<array<int,2>,2> next = {array<int,2>{-1,-1}, array<int,2>{-1,-1}};
                if(dp[0][0]!=-1)next[0][same]=dp[0][0]+same;
                if(dp[0][1]!=-1)next[0][1^same]=dp[0][1]+!same;
                if(dp[1][0]!=-1)next[1][same]=dp[1][0]+same;
                if(dp[1][1]!=-1)next[1][1^same]=dp[1][1]+!same;
                dp=next;
            }
            vector<int> toAdd;
            bool lastDo = !(dp[1][1]==-1||dp[0][0]<dp[1][1]);
            for(int j=0;j<path.size();j++)
            {
                int cur = path[j], nxt = path[(j+1)%path.size()];
                int same = aa[cur]==aa[nxt]||bb[cur]==bb[nxt];
                if(lastDo&&!same||!lastDo&&same)
                {
                    toAdd.push_back(nxt);
                    lastDo=true;
                }
                else
                {
                    lastDo=false;
                }
            }
            ansInds.insert(ansInds.end(), toAdd.begin(), toAdd.end()); 
        }
        cout << ansInds.size() << '\n';
        for(int i=0;i<ansInds.size();i++)
        {
            if(i)cout << ' ';
            cout << ansInds[i]+1;
        }cout << '\n';
    }
    return 0;
}