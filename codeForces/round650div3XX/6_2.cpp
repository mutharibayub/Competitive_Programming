#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>

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
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i].first;
        map<int,int> cnt;
        for(int i=n-1;i>=0;i--)
        {
            arr[i].second=cnt[arr[i].first];
            cnt[arr[i].first]++;
        }cnt.clear();
        set<pair<int,int>> done;
        vector<pair<pair<int,int>,pair<int,int>>> pq;
        for(int i=n-1;i>=0;i--)
        {
            if(!done.empty() && make_pair(arr[i].first-1, 9999999)>(*done.begin()))
            {
                pair<int,int> target = *prev(done.lower_bound(make_pair(arr[i].first-1, 9999999)));
                pq.emplace_back(target,  arr[i]);
            }
            done.insert(arr[i]);
        }done.clear();
        
        sort(pq.begin(), pq.end());
        vector<pair<int,int>> srt = arr;
        sort(srt.begin(), srt.end());

        int ptr = n;
        int ans = n;
        for(int i=n-1;i>=0;i--)
        {
            while(!pq.empty()&&pq.back().first==srt[i])
            {
                while(ptr&&srt[ptr-1]>=pq.back().second)ptr--;
                pq.pop_back();
            }
        
            ans = min(ans, i+n-ptr);
        }
        cout << ans << '\n';
    }
    return 0;
}