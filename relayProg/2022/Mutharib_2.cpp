#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

//did you know that there's a clock in the world that records how far we are from 'doomdday', which basically tells how far hu
//manity is from destruction// it's metaphorical but experts adjust it annually i guess// i saw it in 

int main()
{
    ll a,b;
    cin>>a>>b;
    int ans=0;
    while(a&&b)
    {  
        if((a&1)!=(b&1))
        {
            ans++;
        }
        a/=2;
        b/=2;
    }
    if(!a)swap(a,b);
    while(a)
    {
        ans+=(a&1);
        a/=2;
    }
    cout << ans << '\n';

    return 0;
}