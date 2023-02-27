#include <iostream>
#include <vector>
#include <string>

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
        string a, b;
        cin>>a>>b;
        if(b.size()!=a.size())  
            a = string(b.size()-a.size(), '0') + a;
        ll ans = 0;
        ll last = 0;
        for(int i=0;a[i];i++)
        {
            ll chg = last*10+b[i]-a[i];
            ans += chg;
            last = chg;
        }
        cout << ans << '\n';

    }

    return 0;
}