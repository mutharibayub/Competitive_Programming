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

    ll fib[45];
    fib[0]=1;fib[1]=1;
    for(int i=2;i<45;i++)fib[i]=fib[i-1]+fib[i-2];

    tst
    {
        ll n, x, y;
        cin>>n>>x>>y;
        x--, y--;

        bool canDo[] = {0,0};

        ll sm=0;
        for(int i=n;i>0;i-=2)
        {
            if(sm+fib[i]>y)continue;
            sm+=fib[i];
        }canDo[0]=(sm==y);
        
        sm=0;
        for(int i=n-1;i>0;i-=2)
        {
            if(sm+fib[i]>x)continue;
            sm+=fib[i];
        }canDo[1]=(sm==x);

        cout << (canDo[0]&&canDo[1]?"YES":"NO") << '\n';
    }

    return 0;
}