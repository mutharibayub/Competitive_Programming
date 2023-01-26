#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

void addDivs(vector<bool> &possibs, int num)
{
    for(int i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            possibs[i]=true;
            possibs[num/i]=true;
        }
    }
}

bool checkCount(vector<int> &arr, int mod)
{
    map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        int cnt = (++mp[(arr[i]%mod+mod)%mod]);
        if(cnt>=arr.size()/2)return true;
    }
    return false;
}

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
        for(int i=0;i<n;i++)cin>>arr[i];
        map<int,int> mp;
        bool ok=false;
        for(int i=0;i<n&&!ok;i++)
        {
            int cnt = (++mp[arr[i]]);
            if(cnt>=n/2)ok=true;
        }
        if(ok)
        {
            cout << -1 << '\n';
            continue;
        }
        vector<bool> possibs(2e6+1,false);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff = abs(arr[i]-arr[j]);
                if(!possibs[diff])
                {
                    addDivs(possibs,diff);
                }
            }
        }
        int ans = -1;
        for(int i=2e6+1;i>=0;i--)
        {
            if(possibs[i]&&checkCount(arr,i))
            {
                ans=i;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}