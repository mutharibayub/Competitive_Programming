#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPossible(int n, int d, vector<int> &arr, int target)
{
    bool openSpace = d+1-arr.back()-1>=target+1;
    for(int i=0;i<n&&!openSpace;i++)
    {
        int last = i?arr[i-1]:0;
        openSpace = arr[i]-last-1>=2*target+1;
    }
    vector<int> moveOptions;
    for(int i=0;i<n;i++)
    {
        int prv = i?arr[i-1]:0;
        if(arr[i]-prv-1<target)moveOptions.push_back(i);
    }
    if(moveOptions.size()==0)return true;
    if(moveOptions.size()>=3)return false;
    if(moveOptions.size()==2)
    {
        if(moveOptions.back()-moveOptions.front()>1)return false;
        moveOptions = {moveOptions.front()};
    }
    else if(moveOptions.front())
    {
        moveOptions.push_back(moveOptions.front()-1);
        swap(moveOptions.front(),moveOptions.back());
    }
    if(moveOptions.size()==1)
    {
        int i = moveOptions.front();
        int prv = i?arr[i-1]:0;
        int nxt = i+1<n?arr[i+1]:d+1+target;
        return (openSpace&&nxt-prv-1>=target)||(!openSpace&&nxt-prv-1>=2*target+1);
    }
    else
    {
        int i1 = moveOptions.front();
        int i2 = moveOptions.back();
        int l = i1?arr[i1-1]:0;
        int r = i2+1<n?arr[i2+1]:d+1+target;
        int m1 = arr[i1];
        int m2 = arr[i2];
        if(m1-l-1<target&&r-m2-1<target)return false;
        else if(m1-l-1<target)
        {
            int nxt = m2, prv = l;
            return (openSpace&&nxt-prv-1>=target)||(!openSpace&&nxt-prv-1>=2*target+1);            
        }
        else if(r-m2-1<target)
        {
            int nxt = r, prv = m1;
            return (openSpace&&nxt-prv-1>=target)||(!openSpace&&nxt-prv-1>=2*target+1);   
        }
        else
        {
            return (openSpace&&r-m1-1>=target)||(!openSpace&&r-m1-1>=2*target+1)
                    || (openSpace&&m2-l-1>=target)||(!openSpace&&m2-l-1>=2*target+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int ans=0;
        for(int jump=d;jump;jump/=2)
        {
            while(ans+jump<d&&isPossible(n,d,arr,ans+jump))
            {
                ans+=jump;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}