#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int l=0;
        ll sum=s;
        int bl=-1,br=-1;
        for(int i=0;i<n;i++)
        {
            while(l<i&&sum+arr[i]<0)
            {
                sum-=arr[l];
                l++;
            }
            sum+=arr[i];
            if(sum>=0)
            {
                int len=i-l+1;
                int bestLen=br==-1?0:br-bl+1;
                if(len>bestLen)
                {
                    bl=l,br=i;
                }
            }
            else
            {
                sum-=arr[l];
                l++;
            }
        }
        if(bl==-1)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << bl+1 << ' ' << br+1 << '\n';
        }
    }
}