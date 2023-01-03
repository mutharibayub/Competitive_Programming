#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <algorithm>

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
        int n,m;
        ll ans=0;
        cin>>n>>m;
        vector<ll> b(m);
        map<ll,int> a;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            a[tmp]++;
        }
        for(int i=0;i<m;i++)cin>>b[i];
        for(int i=0;i<m;i++)
        {
            ll smallest = a.begin()->first;
            a[smallest]--;
            if(a[smallest]==0)a.erase(smallest);
            a[b[i]]++;
        }
        for(auto n:a)ans+=n.first*n.second;
        cout << ans << '\n';
    }

    return 0;
}