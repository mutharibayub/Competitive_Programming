#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
        vector<int> arr(n);
        map<int,int>extras;
        vector<int> yes(n,false);
        long long cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            --arr[i];
            if(arr[i]<0)continue;
            if(!yes[arr[i]])yes[arr[i]]=true;
            else extras[arr[i]]++;
        }
        sort(arr.begin(),arr.end());
        int r=n-1;
        for(int i=0;i<=arr[r];i++)
        {
            if(!yes[i])
            {
                if(extras.size())
                {
                    int val=extras.begin()->first;
                    extras[val]--;
                    if(!extras[val])extras.erase(val);
                    cnt+=val-i;
                }
                else
                {
                    cnt+=arr[r]-i;
                    int curVal=arr[r];
                    while(r>=0&&arr[r]==curVal)r--;
                }
            }
            extras.erase(i);
        }
        cout << cnt << '\n';
    }

    return 0;
}