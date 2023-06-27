#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int n=(2<<k);
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        map<int, int> loc;
        bool found=false;
        for(int i=0;i<n&&!found;i++)
        {
            if(loc.find(arr[i])!=loc.end())
            {
                found=true;
                cout << loc[arr[i]]+1 << ' ' << loc[arr[i]]+1 << ' ' << i+1 << ' ' << i+1 << '\n';
            }
            else
            {
                loc[arr[i]]=i;
            }
        }
        if(found)continue;

        map<int, int> leftXor;
        int xr = 0;
        for(int i=0;i<n&&!found;i++)
        {
            xr^=arr[i];
            if(leftXor.find(xr)!=leftXor.end())
            {
                found=true;
                if(arr[i])
                {
                    cout << leftXor[xr]+2 << ' ' << leftXor[xr]+2 << ' ' << leftXor[xr]+3 << ' ' << i+1 << '\n'; 
                }
                else
                {
                    cout << "1 1 2 " << i-1 +1 << '\n';
                }
            }
            leftXor[xr]=i;
        }
        if(found)continue;
        
        assert(false);
    }
    return 0;
}