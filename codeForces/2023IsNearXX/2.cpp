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
        cin>>n>>m;
        vector<int> ans(n,-1);
        int n1=n;
        int n2=1;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==-1)
            {
                ans[i]=n1;
                n1--;
                if(i+m-1<n)
                {
                    ans[i+m-1]=n2;
                    n2++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }

    return 0;
}