#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

class RMQ
{
    vector<vector<ll>> st;
public:
    RMQ(vector<ll> &arr)
    {
        int n = arr.size();
        int bitCount = 0;
        while((1<<bitCount)<=n)bitCount++;
        st.assign(n, vector<ll>(bitCount,-1e9+7));
        for(int i=0;i<n;i++)st[i][0]=arr[i];
        for(int bit=1;bit<bitCount;bit++)
        {
            for(int i=0;i<n;i++)
            {
                if(i+(1<<bit)<=n)
                {
                    st[i][bit]=max(st[i][bit-1],st[i+(1<<(bit-1))][bit-1]);
                }
            }
        }
    }
    ll getMax(int l, int r)
    {
        assert(l<=r);
        if(l==r)return st[l][0];
        int bitCount = 0;
        while(l+(1<<bitCount)<=r)bitCount++;
        bitCount--;
        return max(st[l][bitCount], st[r-(1<<bitCount)+1][bitCount]);
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
        ll n, k, x;
        cin>>n>>k>>x;
        vector<ll> arr(n), lp(n), ln(n), rp(n), rn(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        
        if(x<0)
        {
            k=n-k;
            x*=-1;
        }

        ll ans = 0;
        
        int l,r;

        lp[0]=arr[0]+x;
        ln[0]=arr[0]-x;
        rp[n-1]=arr[n-1]+x;
        rn[n-1]=arr[n-1]-x;
        for(int i=1;i<n;i++)
        {
            lp[i]=lp[i-1]+arr[i]+x;
            ln[i]=ln[i-1]+arr[i]-x;
        }
        for(int i=n-2;i>=0;i--)
        {
            rp[i]=rp[i+1]+arr[i]+x;
            rn[i]=rn[i+1]+arr[i]-x;
        }
        RMQ rpp(rp), rnn(rn), lpp(lp), lnn(ln);
        if(k)
        for(int i=0;i<n;i++)
        {
            l=i,r=l+k-1;
            ans=max(ans, max(0ll,lpp.getMax(l, min(1ll*r,n-1))-(l?lp[l-1]:0)));
        }
        for(int i=0;i<n&&i+k-1<n;i++)
        {
            l=i,r=l+k-1;
            ll bestLeft = (l?(max(0ll,rnn.getMax(0,l-1)-rn[l])):0);
            ll bestRight = (r+1<n?max(0ll,lnn.getMax(r+1,n-1)-(r>=0?ln[r]:0)):0);
            if(l>r)
            {
                ans=max(ans, bestLeft+bestRight);
                continue;
            }
            ll midSum = lp[r]-(l?lp[l-1]:0);
            ll midLeft = max(0ll,lpp.getMax(l, r)-(l?lp[l-1]:0));
            ll midRight = max(0ll,rpp.getMax(l, r)-(r+1<n?rp[r+1]:0));
            ans = max(ans, midSum+bestLeft+bestRight);
            ans = max(ans, midLeft+bestLeft);
            ans = max(ans, midRight+bestRight);
        }
        cout << ans << '\n';
    }

    return 0;
}