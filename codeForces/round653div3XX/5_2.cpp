#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <cassert>

using namespace std;

int check(vector<int> *bbCnt, int used, int req, int m, int idx)
{
    int before=0;
    if(idx)before+=min(req, bbCnt[0][idx-1]);
    if(idx)before+=min(req, bbCnt[1][idx-1]);
    int total = used+(idx+2*req)-before;
    if(total<m)return -1;
    else if(total==m)return 1;
    else return 0;
}

int getSum(vector<array<int,2>> *bb, vector<array<int,2>> &allb, vector<int> *bbCnt, int used, int idx)
{
    int totalSum=0, bfr=0;
    if(used)totalSum+=bb[0][used-1][0];
    if(used)totalSum+=bb[1][used-1][0];
    if(idx)
    {
        bfr=min(used, bbCnt[0][idx-1]);
        if(bfr)totalSum-=bb[0][bfr-1][0];
        bfr=min(used, bbCnt[1][idx-1]);
        if(bfr)totalSum-=bb[1][bfr-1][0];
        totalSum+=allb[idx-1][0];
    }
    return totalSum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    vector<array<int,2>> both;
    vector<array<int,2>> bb[3], allb;
    for(int i=0;i<n;i++)
    {
        int t, a, b;
        cin>>t>>a>>b;
        if(!(a&&b))
        {
            allb.push_back({t,i});
            if(a)
                bb[0].push_back({t,i});
            else if(b)
                bb[1].push_back({t,i});
            else
                bb[2].push_back({t,i});
        }
        else
            both.push_back({t,i});
    }
    sort(both.begin(), both.end());
    
    if(allb.empty())
    {
        if(both.size()<m)
        {
            cout << -1 << '\n';
        }
        else
        {
            int sum = 0;
            for(int i=0;i<m;i++)sum+=both[i][0];
            cout << sum << '\n';
            for(int i=0;i<m;i++)
            {
                if(i)cout << ' ';
                cout << both[i][1]+1;
            }cout << '\n';
        }
        return 0;
    }

    for(int i=0;i<3;i++)
    {
        sort(bb[i].begin(), bb[i].end());
    }
    sort(allb.begin(), allb.end());
    int ptr[3]={0,0,0};
    vector<int> bbCnt[3];
    for(int i=0;i<3;i++)
    {
        bbCnt[i].resize(allb.size(), 0);
    }
    for(int i=0;i<allb.size();i++)
    {
        for(int j=0;j<3;j++)
        {
            if(ptr[j]<bb[j].size()&&bb[j][ptr[j]]==allb[i])
            {
                bbCnt[j][i]+=1;
                ptr[j]++;
                break;
            }
        }
        if(i)
            for(int j=0;j<3;j++)
                bbCnt[j][i]+=bbCnt[j][i-1];
    }

    for(int i=1;i<both.size();i++)
        both[i][0]+=both[i-1][0];
    for(int i=1;i<allb.size();i++)
        allb[i][0]+=allb[i-1][0];
    for(int j=0;j<3;j++)
        for(int i=1;i<bb[j].size();i++)
            bb[j][i][0]+=bb[j][i-1][0];

    int ans = 2e9+7;
    int bestI=-1, bestCur=-1, bestReq=-1;
    for(int i=0;i<=both.size();i++)
    {
        int total=0;
        int bothCount=i;
        int req = max(k-bothCount, 0);
        if(bb[0].size()<req||bb[1].size()<req)continue;
        total+=bothCount+2*req;
        if(total>m)continue;
        int cur=0;
        for(int jmp=allb.size();jmp;jmp/=2)
        {
            while(cur+jmp<=allb.size()&&check(bbCnt, bothCount, req, m, cur+jmp))cur+=jmp;
        }
        if(check(bbCnt, bothCount, req, m, cur)==-1)continue;
        int sum = (i?both[bothCount-1][0]:0)+getSum(bb, allb, bbCnt, req, cur);
        if(ans > sum)
        {
            ans = sum;
            bestI = i;
            bestCur = cur;
            bestReq = req;
        }
    }
    if(ans == 2e9+7)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
        set<int> indices;
        for(int i=0;i<bestI;i++)
        {
            indices.insert(both[i][1]);
        }
        for(int i=0;i<bestReq;i++)
        {
            indices.insert(bb[0][i][1]);
            indices.insert(bb[1][i][1]);
        }
        for(int i=0;i<bestCur;i++)
        {
            indices.insert(allb[i][1]);
        }
        bool flag = false;
        for(auto ele:indices)
        {
            if(flag)cout << ' ';
            cout << ele+1;
            flag = true;
        }cout << '\n';
        assert(indices.size()==m);
        assert(ans>0);
    }

    return 0;
}