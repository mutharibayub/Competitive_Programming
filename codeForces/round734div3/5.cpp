#include <iostream>
#include <vector>
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        vector<vector<int>> locs(n+1);
        vector<vector<int>> rq(n);
        vector<int> subArr(n+1,0);
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)locs[arr[i]].push_back(i); 
        int ans=1e9+7;
        for(int i=0;i<n;i++)
        {
            auto it = lower_bound(locs[i+1].begin(), locs[i+1].end(), i);
            for(;it!=locs[i+1].end();it++)
            {
                rq[i].push_back(*it-i);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(rq[i].empty())continue;
            int ptr=rq[i].size()-1;
            for(int j=rq[i].back();j>=0;j--)
            {
                while(ptr&&rq[i][ptr-1]>=j)ptr--;
                subArr[rq[i][ptr]]=max(subArr[rq[i][ptr]], subArr[j]+1);
            }
            for(auto num:rq[i])
                if(subArr[num]>=k)ans=min(ans, num);
        }
        cout << (ans==1e9+7?-1:ans) << '\n';
    }    
}