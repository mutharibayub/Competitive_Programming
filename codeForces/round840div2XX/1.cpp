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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int mx=0,mn=0;
        for(int i=0;i<10;i++)
        {
            bool zr=false;
            bool on=false;
            for(int j=0;j<n;j++)
            {
                zr|=(arr[j]&(1<<i))==0;
                on|=(arr[j]&(1<<i))!=0;
            }
            if(on)mx|=(1<<i);
            if(!zr)mn|=(1<<i);
        }
        cout << mx-mn << '\n';
    }

    return 0;
}