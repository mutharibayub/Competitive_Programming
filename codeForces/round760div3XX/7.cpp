#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 2e5;
const int N2 = 2*N;

int parent[N2];
int cntMain[N2];
array<int,2> rng[N2];
ll bestSum[N2];

int getParent(int i)
{
    if(parent[i]!=i)
    {
        parent[i]=getParent(parent[i]);
    }
    return parent[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q,n2;
    ll ans=0;
    cin>>n>>m>>q;
    vector<array<int,2>> allVals(n+m);
    vector<array<int,2>> queries(q);
    vector<ll> finalVal(q);
    vector<array<int,3>> toMerge;
    for(int i=0;i<n+m;i++)
    {
        int val;
        cin>>val;
        parent[i]=i;
        cntMain[i]+=i<n;
        allVals[i]={val,i};
        bestSum[i]=i<n?val:0;
        ans += bestSum[i];
    }
    sort(allVals.begin(),allVals.end());
    vector<ll> sum(n+m,0);
    for(int i=0;i<allVals.size();i++)
    {
        rng[allVals[i][1]]={i,i};
        sum[i]=(i?sum[i-1]:0)+allVals[i][0];
    }
    for(int i=0;i+1<allVals.size();i++)
    {
        toMerge.push_back({allVals[i+1][0]-allVals[i][0], allVals[i][1], allVals[i+1][1]});
    }
    sort(toMerge.begin(),toMerge.end());

    for(int i=0;i<q;i++)
    {
        cin>>queries[i][0];
        queries[i][1]=i;
    }
    sort(queries.begin(),queries.end());

    int idx = 0;
    for(int i=0;i<queries.size();i++)
    {
        while(idx<toMerge.size()&&toMerge[idx][0]<=queries[i][0])
        {
            int u = toMerge[idx][1];
            int v = toMerge[idx][2];
            int p1 = getParent(u), p2 = getParent(v);
            int sz1 = rng[p1][1]-rng[p1][0]+1, sz2 = rng[p2][1]-rng[p2][0]+1;
            if(sz1<sz2)
            {
                swap(u,v);
                swap(p1,p2);
                swap(sz1,sz2);
            }
            parent[p2]=p1;
            rng[p1]={min(rng[p1][0],rng[p2][0]),max(rng[p1][1],rng[p2][1])};
            if(cntMain[p2]||cntMain[p1])
            {
                cntMain[p1]+=cntMain[p2];
                ans-=bestSum[p1];
                ans-=bestSum[p2];
                int endIndex = rng[p1][1];
                int startIndex = endIndex-cntMain[p1]+1;
                bestSum[p1] = sum[endIndex]-(startIndex?sum[startIndex-1]:0);
                ans+=bestSum[p1];
            }
            idx++;
        }
        finalVal[queries[i][1]]=ans;
    }
    for(int i=0;i<finalVal.size();i++)
    {
        cout << finalVal[i] << '\n';
    }


    return 0;
}