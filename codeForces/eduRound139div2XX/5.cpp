#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <utility>
#include <map>

using namespace std;

typedef long long ll;

vector<int> arr;
map<pair<int,vector<int>>, ll> dp;

ll count(int idx, vector<int> li)
{
    if(idx==arr.size())return 0;
    auto it = dp.find({idx,li});
    if(it!=dp.end())return it->second;
    auto tmp=li;
    bool add = true;
    for(int i=0;i<li.size();i++)
    {
        if(arr[idx]&li[i])
        {
            li[i]=arr[idx];
            add=false;
            break;
        }
    }
    if(add&&arr[idx])
    {
        li.push_back(arr[idx]);
    }
    return (dp[{idx,tmp}]=add*(arr.size()-idx)*1ll+count(idx+1,li)); 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    arr.assign(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += count(i, {});
    }
    cout << ans << '\n';

    return 0;
}