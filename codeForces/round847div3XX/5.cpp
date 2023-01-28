#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <set>

using namespace std;

typedef long long ll;

int countBits(int x)
{
    int cnt=0;
    while(x)
    {
        cnt+=(x%2);
        x/=2;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        int n1=0,n2=0;
        n1 = x;
        for(int i=30;i>=0;i--)
        {
            int bitNum = 1<<i;
            if((x&bitNum)==0&&n1+n2+2ll*bitNum<=2ll*x)
            {
                n1+=bitNum;
                n2+=bitNum;
            }
        }
        if(n1+n2==2ll*x)
        {
            cout << n1 << ' ' << n2 << '\n';
        }
        else
        {
            cout << -1 << '\n';    
        }

    }

    return 0;
}