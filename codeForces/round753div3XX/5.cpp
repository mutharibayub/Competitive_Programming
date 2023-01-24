#include <iostream>
#include <vector>

using namespace std;

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
        string s;
        cin>>s;
        int mxx=0,mxy=0,mnx=0,mny=0;
        int x=0,y=0;
        int ax=0,ay=0;
        for(int i=0;s[i];i++)
        {
            int cy=0,cx=0;
            cy+=s[i]=='D';
            cy-=s[i]=='U';
            cx-=s[i]=='L';
            cx+=s[i]=='R';
            x+=cx;
            y+=cy;
            mxx=max(mxx,x);
            mxy=max(mxy,y);
            mnx=min(mnx,x);
            mny=min(mny,y);
            if(mxx-mnx+1>m||mxy-mny+1>n)
            {
                break;
            }
            ax=mxx,ay=mxy;
        }
        x=m-ax-1;
        y=n-ay-1;
        cout << y+1 << ' ' << x+1 << '\n';
    }

    return 0;
}