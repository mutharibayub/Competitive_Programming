#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

ll MOD = 998244353;
const int N=1e5+1;

set<int> al[N];

ll norm(ll n)
{
    return (n%MOD+MOD)%MOD;
}

ll power(ll n, ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
        {
            ans=norm(ans*n);
        }
        n=norm(n*n);
        e/=2;
    }
    return ans;
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
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        vector<bool> ensured(n+1,false);
        vector<bool> done(n,false);
        bool no=false;
        for(int i=1;i<=n;i++)al[i].clear();
        for(int i=0;i<n&&!no;i++)
        {
            if(a[i]!=b[i])
            {
                al[a[i]].insert(i);
                al[b[i]].insert(i);
            }
            else
            {
                if(ensured[a[i]])no=true;
                else ensured[a[i]]=true;
                done[i]=true;
            }
        }
        for(int i=1;i<=n&&!no;i++)
        {
            int node=i,idx,other;
            if(!ensured[node]&&al[node].size()==0)
            {
                no=true;
            }
            else
            {
                idx=*(al[node].begin());
                while(!ensured[node]&&al[node].size()==1)
                {
                    other=a[idx];
                    if(other==node)other=b[idx];
                    done[idx]=true;
                    ensured[node]=true;
                    al[other].erase(idx);
                    node=other;
                    idx=*(al[node].begin());
                    if(!ensured[node]&&al[node].size()==0)
                    {
                        no=true;
                    }
                }
            }
        }
        int cycleCount=0;
        int anyCount=0;
        for(int i=0;i<n&&!no;i++)
        {
            if(a[i]==b[i])anyCount++;
            else if(!done[i])
            {  
                int node=a[i],other,idx=i;
                while(!ensured[node])
                {
                    ensured[node]=true;
                    other=a[idx];
                    if(node==other)other=b[idx];
                    al[other].erase(idx);
                    done[idx]=true;
                    if(!ensured[other])
                    {
                        if(al[other].size()!=1)
                        {
                            no=true;
                            break;
                        }
                        else
                        {
                            idx=*(al[other].begin());
                            node=other;
                        }
                    }
                }
                cycleCount++;
            }
        }
        if(no)
        {
            cout << 0 << '\n';
            continue;
        }
        ll ans=1;
        ans = norm(ans*power(n,anyCount));
        ans = norm(ans*power(2,cycleCount));
        cout << ans << '\n';
    }

    return 0;
}