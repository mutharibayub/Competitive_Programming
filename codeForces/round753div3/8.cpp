#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e6+1;

vector<array<int,3>> rngs[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<int> toClear;

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n),b(n),ae(n,0),be(n,0),m(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i]>>m[i];
        }
        for(int i=0;i<n;i++)
        {
            int sum = a[i]+b[i]-m[i];
            toClear.insert(sum);
            int minPossible = max(a[i]-m[i],0);
            int maxPossible = a[i]-max(m[i]-b[i],0);
            rngs[sum].push_back({minPossible,maxPossible,i});
        }
        for(auto sum:toClear)
        {
            sort(rngs[sum].begin(),rngs[sum].end());
            int cnt=1;
            int s = 1;
            int last=0;
            array<int,2> rng = {rngs[sum][0][0],rngs[sum][0][1]};
            for(;s<rngs[sum].size();s++)
            {
                if(rng[1]<rngs[sum][s][0])
                {
                    for(int i=last;i<s;i++)
                    {
                        int idx = rngs[sum][i][2];
                        ae[idx]=a[idx]-rng[0];
                    }
                    last=s;
                    cnt++;
                    rng = {rngs[sum][s][0],rngs[sum][s][1]};
                }
                else
                {
                    rng[0]=rngs[sum][s][0];
                    rng[1]=min(rng[1],rngs[sum][s][1]);
                }
            }
            for(int i=last;i<s;i++)
            {
                int idx = rngs[sum][i][2];
                ae[idx]=a[idx]-rng[0];
            }
            ans+=cnt;
        }

        for(int i=0;i<n;i++)
        {
            be[i]=m[i]-ae[i];
        }

        cout << ans << '\n';
        for(int i=0;i<n;i++)
        {
            cout << ae[i] << ' ' << be[i] << '\n';
        }   

        for(auto sum:toClear)
        {
            rngs[sum].clear();
        }
        toClear.clear();
    }

    return 0;
}