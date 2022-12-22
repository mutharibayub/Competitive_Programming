#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int x, int y)
{
    if(y>x)swap(x,y);
    if(!y)return x;
    return GCD(y,x%y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        a=GCD(a,b);
        int ans=0;
        for(int i=1;i*i<=a;i++)
        {
            if(a%i==0)
            {
                if(i*i==a)ans--;
                ans+=2;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}