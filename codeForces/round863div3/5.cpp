#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

#define tst int tttt;cin>>tttt;while(tttt--)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    tst
    {
        ll num;
        cin>>num;

        ll ans=0;
        ll mul=1;
        while(num)
        {
            ans+=(num%9)*mul;
            num/=9;
            mul*=10;
        }
        
        string out = to_string(ans);
        for(int i=0;i<out.size();i++)
        {
            if(out[i]>='4')out[i]++;
        }

        cout << out << '\n';
    }

    return 0;
}