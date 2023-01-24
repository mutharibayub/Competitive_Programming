#include <iostream>
#include <vector>
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
        vector<int> a(n),b(n),ae(n,0),be(n,0);
        for(int i=0;i<n;i++)cin>>a[i]>>b[i];
        for(int i=0;i<n;i++)
        {
            ae[i]=min(a[i],m);
            be[i]=m-ae[i];
        }
        ll diff = 0;
        for(int i=0;i<n;i++)
        {
            diff-=a[i]-ae[i];
            diff+=b[i]-be[i];
        }
        for(int i=0;i<n&&diff>1;i++)
        {
            ll toTransfer = min({diff/2,1ll*ae[i],1ll*b[i]-be[i]});
            be[i]+=toTransfer;
            ae[i]-=toTransfer;
            diff-=2*toTransfer;
        }
        cout << abs(diff) << '\n';
        for(int i=0;i<n;i++)
        {
            cout << ae[i] << ' ' << be[i] << '\n';
        }
    }

    return 0;
}