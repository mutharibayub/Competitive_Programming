#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class FenwickTree
{
    vector<ll> arr;
public:
    FenwickTree(){}
    FenwickTree(int n)
    {
        assign(n);
    }
    void assign(int n)
    {
        arr.resize(n+1,0);
    }
    void add(int i, ll n)
    {
        i++;
        while(i<arr.size())
        {
            arr[i]+=n;
            i+=i&-i;
        }
    }
    ll get(int i)
    {
        i++;
        ll ans = 0;
        while(i)
        {
            ans += arr[i];
            i-=i&-i;
        }
        return ans;
    }
};

int getCount(vector<ll> &sum, int s, int e)
{
    return s?sum[e]-sum[s-1]:sum[e];
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
        string s;
        cin>>s;
        vector<ll> sum(n,0);
        FenwickTree fwt[3];
        for(int i=0;i<3;i++)fwt[i].assign(2*n+1);
        for(int i=0;i<n;i++)
        {
            sum[i]+=(s[i]=='+'?1:-1)+(i?sum[i-1]:0);
        }
        int offset = n;
        ll ans = 0;
        fwt[0].add(offset+0,+1);
        for(int i=0;i<n;i++)
        {
            int mod = (sum[i]%3+3)%3;
            ans += fwt[mod].get(n+offset)-fwt[mod].get(sum[i]+offset-1);
            fwt[mod].add(sum[i]+offset,+1);
        }
        cout << ans << '\n';
    }

    return 0;
}