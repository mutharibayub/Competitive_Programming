#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>

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
        ll c;
        cin>>n>>c;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        vector<int> realMin(n);
        vector<ll> sum(n);
        
        for(int i=1;i<=n;i++)
        {
            int leftMin = i+a[i];
            realMin[i-1] = leftMin;
        }
        sort(realMin.begin(), realMin.end());

        int canUptil=-1;
        for(int i=0;i<n;i++)
        {
            sum[i]=(i-1>=0?sum[i-1]:0)+realMin[i];
            if(sum[i]<=c)canUptil=i;
        }

        cout << canUptil+1 << '\n';

    }

    return 0;

}