#include <iostream> 
#include <vector>

using namespace std;

int GCD(int x, int y)
{
    if(x<y)swap(x,y);
    if(!y)return x;
    return GCD(y,x%y);
}

int LCM(int x, int y)
{
    return (1ll*x*y)/GCD(x,y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI = false;
    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int val,ans,n1=1;
        for(int i=1;i<=16;i++)n1=LCM(n1,i);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>val;
                if(i%2^j%2)
                {
                    ans=n1+val*val*val*val;
                }
                else
                {
                    ans=n1;
                }
                cout << ans << ' ';
            }cout << '\n';
        }
    }

    return 0;
}