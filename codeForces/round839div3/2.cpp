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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int mn = min({a,b,c,d});
        int mx = max({a,b,c,d});
        if(a>d)swap(a,d);
        if(b>c)swap(b,c);
        cout << (mn==a&&mx==d||mn==b&&mx==c?"YES":"NO") << '\n';
    }

    return 0;
}