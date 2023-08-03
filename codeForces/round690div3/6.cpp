#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1, 0);
    }
    void init(int n, int val)
    {
        arr.clear();
        arr.resize(n+1, val);
    }
    void update(int i, int add)
    {
        i++;
        while(i<arr.size())
        {
            arr[i]+=add;
            i+=i&-i;
        }
    }
    int get(int i)
    {
        i++;
        int out=0;
        while(i)
        {
            out+=arr[i];
            i-=i&-i;
        }
        return out;
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
        vector<array<int,2>> segs(n);
        vector<int> cnt(n, 0);
        vector<int> coord;
        for(int i=0;i<n;i++)cin>>segs[i][0]>>segs[i][1];
        for(int i=0;i<n;i++)
        {
            coord.push_back(segs[i][0]);
            coord.push_back(segs[i][1]);
        }
        sort(coord.begin(), coord.end());
        sort(segs.begin(), segs.end());
        FenwickTree fwt(coord.size());
        int cur = -1;
        vector<int> vals;
        for(int i=0;i<n;i++)
        {
            int l=segs[i][0], r=segs[i][1];
            if(cur<l)
            {
                for(auto val:vals)
                {
                    fwt.update(val, +1);
                }
                vals.clear();
                cur=l;
            }
            int ll=lower_bound(coord.begin(), coord.end(), l)-coord.begin();
            int rr=lower_bound(coord.begin(), coord.end(), r)-coord.begin();
            int cntt = fwt.get(rr)-(ll?fwt.get(ll-1):0);
            cnt[i]+=cntt;
            vals.push_back(rr);
        }
        fwt.init(coord.size(), 0);
        for(int i=0;i<n;i++)
        {
            fwt.update(lower_bound(coord.begin(), coord.end(), segs[i][0])-coord.begin(), +1);
        }
        for(int i=0;i<n;i++)
        {
            int l=segs[i][0], r=segs[i][1];
            int ll=lower_bound(coord.begin(), coord.end(), l)-coord.begin();
            int rr=lower_bound(coord.begin(), coord.end(), r)-coord.begin();
            int cntt = fwt.get(rr)-(ll?fwt.get(ll-1):0);
            cnt[i]+=cntt;
        }
        int ans = 0;
        for(int i=0;i<n;i++)ans=max(ans, cnt[i]);
        cout << n-ans << '\n';
    }
    return 0;
}