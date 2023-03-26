#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int nn, kk;
        cin>>nn>>kk;
        vector<int> pts(nn);
        int tmp;
        for(int i=0;i<nn;i++)cin>>pts[i];
        for(int i=0;i<nn;i++)cin>>tmp;
        sort(pts.begin(), pts.end());
        int curBest = 0, ans = 0;
        vector<int> cnt(nn, 0);
        for(int i=nn-1;i>=0;i--)
        {
            int cov = lower_bound(pts.begin(), pts.end(), pts[i]+kk+1)-pts.begin()-i;
            curBest = max(curBest, cov);
            cnt[i] = curBest;
            if(i+cov<nn)
            {
                cov+=cnt[i+cov];
            }
            ans=max(ans, cov);
        }
        cout << ans << '\n';
    }

    return 0;
}