#include <iostream>
#include <vector>
#include <map>
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
        cin>>n>>m;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        map<int, int> ts;
        int tmp=a[0];
        ts[0]=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]<tmp)
            {
                tmp=a[i];
                ts[i]=a[i];
            }
        }
        for(int i=0;i<m;i++)
        {
            int idx, d;
            cin>>idx>>d;
            idx--;
            a[idx]-=d;
            auto it = (--ts.lower_bound(idx+1));
            if(a[idx] >= it->second || it->first==idx)
            {
                it->second=min(it->second, a[idx]);
            }
            else
            {
                ts[idx]=a[idx];
            }
            vector<int> toRemove;
            it = (ts.lower_bound(idx+1));
            for(;it!=ts.end()&&it->second>=a[idx];it++)
            {
                toRemove.push_back(it->first);
            }
            for(auto num:toRemove)
            {
                ts.erase(num);
            }
            cout << ts.size() << ' ';
        }cout << '\n';
    }

    return 0;
}