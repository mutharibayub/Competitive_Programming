#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1);
    }
    void update(int i, int n)
    {
        i++;
        while(i<arr.size())
        {
            arr[i]+=n;
            i+=i&-i;
        }
    }
    int get(int i)
    {
        i++;
        int ans = 0;
        while(i>0)
        {
            ans+=arr[i];
            i-=i&-i;
        }
        return ans;
    }
};

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
        vector<int> arr(n),srt;
        for(int i=0;i<n;i++)cin>>arr[i];
        srt=arr;
        sort(srt.begin(),srt.end());
        FenwickTree fwt(n);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int ind = lower_bound(srt.begin(),srt.end(),arr[i])-srt.begin();
            int below = ind?fwt.get(ind-1):0;
            int above = i-fwt.get(ind);
            ans+=1ll*min(below,above);
            fwt.update(ind,+1);
        }
        cout << ans << '\n';
    }

    return 0;
}