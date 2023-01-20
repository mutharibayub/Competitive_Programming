#include <iostream>
#include <vector>
#include <set>
#include <map>

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
        int n;
        cin>>n;
        vector<bool> avl(n+1,false);
        map<int,int> extra;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(!avl[x])avl[x]=true;
            else extra[x]++;
        }
        vector<ll> ans(n+1,-1);
        vector<ll> last(n+1,-1);
        last[0]=0;
        ans[0]=avl[0]+(extra.find(0)==extra.end()?0:extra[0]);
        for(int i=1;i<=n;i++)
        {
            if(last[i-1]!=-1)
            {
                if(avl[i-1])
                {
                    last[i]=last[i-1];
                    ans[i]=last[i]+(avl[i]+(extra.find(i)==extra.end()?0:extra[i]));
                }
                else if(extra.size())
                {
                    auto it = (--extra.lower_bound(i-1));
                    if(it!=extra.end()&&it->first<i-1)
                    {
                        int toConvert = it->first;
                        extra[toConvert]--;
                        if(!extra[toConvert])extra.erase(toConvert);
                        last[i]=last[i-1]+(i-1-(toConvert));
                        avl[i-1]=true;
                        ans[i]=last[i]+(avl[i]+(extra.find(i)==extra.end()?0:extra[i]));
                    }
                }
            }
        }
        for(int i=0;i<=n;i++)
        {
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }
    
    return 0;
}