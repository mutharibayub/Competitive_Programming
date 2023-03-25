// incase the problem wanted values that were equal to k

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <set>

using namespace std;

typedef long long ll;

int bitCount(int i)
{
    int cnt=0;
    while(i)
    {
        cnt+=(i&1);
        i/=2;
    }return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> perms;
    for(int i=0;i<(1<<10);i++)
    {
        if(bitCount(i)==5)
        {
            vector<int> form;
            for(int j=0;j<10;j++)
            {
                if(i&(1<<j))
                {
                    form.push_back(j);
                }
            }
            sort(form.begin(), form.end());
            do
            {
                perms.push_back(form);
            } while (next_permutation(form.begin(), form.end()));
        }
    }
    sort(perms.begin(), perms.end());

    int t; 
    cin>>t;
    while(t--)
    {
        vector<int> arr(10);
        for(int i=0;i<10;i++)cin>>arr[i];
        int k;
        cin>>k;

        vector<int> ans;

        map<pair<int, ll>, vector<int>> dp;

        for(auto perm:perms)
        {
            ll sum = 0;
            bool ok = true;
            int mask = 0;
            for(int i=0;i<5&&ok;i++)
            {
                sum+=1ll*perm[i]*arr[5+i];
                mask |= (1<<perm[i]);
                if(sum>k)ok=false;
            }           
            if(!ok)continue;
            if(dp.find({mask, sum})==dp.end())dp[{mask,sum}]=perm;
        }
        for(auto perm:perms)
        {
            ll sum = 0;
            bool ok = true;
            int mask = 0;
            for(int i=0;i<5&&ok;i++)
            {
                sum+=1ll*perm[i]*arr[i];
                mask |= (1<<perm[i]);
                if(sum>k)ok=false;
            }    
            if(!ok)continue;
            int invMask = ((1<<10)-1)^mask;
            if(dp.find({invMask, k-sum})==dp.end())continue;
            ans = perm;
            ans.insert(ans.end(), dp[{invMask, k-sum}].begin(), dp[{invMask, k-sum}].end());
            break;
        }
        if(ans.size()==0)
        {
            cout << -1 << '\n';
        }
        else
        {
            for(int i=0;i<10;i++)
            {
                if(i)cout << ' ';
                cout << ans[i];
            }cout << '\n';
        }
   }
}