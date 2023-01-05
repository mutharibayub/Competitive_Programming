#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <array>

using namespace std; 

typedef long long ll;

inline ll getMax(ll a, ll b)
{
    return max(a+b,abs(a-b)*2ll);
}

inline ll getSum(const array<ll,3> &a)
{
    return a[0]+a[1]+a[2];
}

array<ll,3> doOp(array<ll,3> a, int i, int j)
{
    ll n1=a[i],n2=a[j];
    if(n1<n2)swap(n1,n2);
    while(i<=j)
    {
        a[i]=n1-n2;
        i++;
    }
    return a;
}

inline bool midPeak(const array<ll,3> &a)
{
    return a[1]>a[0]&&a[1]>a[2];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI=true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        ll ans=0;
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)ans+=arr[i];
        if(n==2)
        {
            ans=getMax(arr[0],arr[1]);
        }
        else if(n==3)
        {
            queue<array<ll,3>> q;
            set<array<ll,3>> done;
            done.insert({arr[0],arr[1],arr[2]});
            q.push({arr[0],arr[1],arr[2]});
            while(!q.empty())
            {
                array<ll,3> top=q.front();
                q.pop();
                bool midBig = midPeak(top);
                ans=max(ans,getSum(top));
                if(!midBig)
                {
                    ans=max(ans,max(top[0],top[2])*3);
                    continue;
                }
                for(int i=0;i<3;i++)
                {
                    for(int j=i+1;j<3;j++)
                    {
                        array<ll,3> nxt=doOp(top,i,j);
                        if(done.find(nxt)!=done.end())continue;
                        done.insert(nxt);
                        q.push(nxt);
                    }
                }    
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                ans=max(ans,arr[i]*n);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}