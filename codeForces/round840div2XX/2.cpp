#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std; 

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI=true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i].second;
        for(int i=0;i<n;i++)cin>>arr[i].first;
        sort(arr.begin(),arr.end());
        int ptr=0;
        int dec=0;
        bool win=true;
        while(1)
        {
            dec+=k;
            while(ptr<n&&arr[ptr].second-dec<=0)ptr++;
            if(ptr>=n)break;
            k-=arr[ptr].first;
            if(k<=0)
            {
                win=false;
                break;
            }
        }
        cout << (win?"YES":"NO") << '\n';
    }

    return 0;
}