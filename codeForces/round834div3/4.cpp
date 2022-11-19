#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

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
        ll n,m,tmp;
        cin>>n>>m;
        int fiveCount=0;
        int twoCount=0;
        tmp=n;
        ll ans=1;
        while(n%5==0)
        {
            n/=5;
            fiveCount++;
        }
        while(n%2==0)
        {
            n/=2;
            twoCount++;
        }
        while(1)
        {
            if(fiveCount==twoCount && ans*10<=m)
            {
                ans*=10;
                fiveCount++, twoCount++;
            }
            else if(fiveCount>twoCount && ans*2<=m)
            {
                ans*=2;
                twoCount++;
            }
            else if(fiveCount<twoCount && ans*5<=m)
            {
                ans*=5;
                fiveCount++;
            }
            else
            {
                ans*=m/ans;
                break;
            }
        }
        ans *= tmp;
        cout << ans << '\n';
    }


    return 0;
}