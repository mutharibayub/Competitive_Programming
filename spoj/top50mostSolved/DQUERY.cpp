#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

#define MAX_NUMBER int(1e6)

int SQUARE_ROOT = 174;

bool cmp(array<int,3>& q1, array<int,3>& q2)
{
    if(q1[0]/::SQUARE_ROOT == q2[0]/::SQUARE_ROOT)
    {
        if((q1[0]/::SQUARE_ROOT)%2 == 0)
        {
            return q1[1]<q2[1];
        }
        else
        {
            return q1[1]>q2[1];
        }
    }
    return q1[0]<q2[0]; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    int m;
    cin>>m;
    vector<array<int,3>> queries(m);
    for(int i=0;i<m;i++)
    {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][0]--;
        queries[i][2] = i;
    }
    sort(queries.begin(), queries.end(), cmp);

    vector<int> sols(queries.size());
    int ans=0;
    int l=0,r=0;
    vector<int> freq(MAX_NUMBER+1, 0); 
    for(auto query:queries)
    {
        while(l<query[0])
        {
            ans -= --freq[arr[l++]]==0?1:0;
        }
        while(l>query[0])
        {
            ans += ++freq[arr[--l]]==1?1:0;
        }
        while(r<query[1])
        {
            ans += ++freq[arr[r++]]==1?1:0;
        }
        while(r>query[1])
        {
            ans -= --freq[arr[--r]]==0?1:0;
        }
        sols[query[2]] = ans;
    }
    for(auto it:sols)
    {
        cout<<it<<'\n';
    }

    return 0;
}