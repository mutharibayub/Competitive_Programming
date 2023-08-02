#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int getDist(int r1, int c1, int r2, int c2)
{
    int pCost = !(((r1+c1)%2==1)||(r2-r1>c2-c1));
    int extra = (r2-r1) - (c2-c1);
    pCost *= c2-c1;
    pCost += (extra + ((r1+c1)%2==1) )/2;
    return pCost;
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
        vector<pair<int, int>> cc(n);
        for(int i=0;i<n;i++)cin>>cc[i].first;
        for(int i=0;i<n;i++)cin>>cc[i].second;
        sort(cc.rbegin(), cc.rend());
        if(cc.back()!=pair<int,int>({1,1}))cc.push_back({1,1});
        ll ans = 0;
        for(int i=cc.size()-1;i>0;i--)
        {
            ans += getDist(cc[i].first, cc[i].second, cc[i-1].first, cc[i-1].second);
        }
        cout << ans << '\n';
    }

    return 0;
}