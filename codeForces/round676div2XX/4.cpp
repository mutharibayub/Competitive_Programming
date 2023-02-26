#include <iostream>
#include <vector>

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
        int r,c;
        cin>>r>>c;
        ll costs[8];
        ll tc[6];
        for(int i=0;i<6;i++)
        {
            cin>>tc[i];
        }
        for(int i=0;i<6;i++)
        {
            tc[i]=min(tc[i], tc[(i+5)%6]+tc[(i+1)%6]);
        }
        for(int i=0;i<8;i++)costs[i]=1e15+1;
        int tmp = 0;
        for(int i=0;i<6;i++)
        {
            costs[i+tmp]=tc[i];
            if(i==1||i==4)tmp++;
        }
        costs[2]=costs[1]+costs[3];
        costs[6]=costs[5]+costs[7];
        int center=-1;
        if(r>=0&&c>=0)
        {
            center=0;
        }
        else if(r>=0&&c<0)
        {
            center=6;swap(r,c);
        }
        else if(r<0&&c>=0)
        {
            center=2;swap(r,c);
        }
        else
        {
            center=4;
        }
        r=abs(r),c=abs(c);
        ll ans = 0;
        if(r||c)
        {
            int mn = min(r,c);
            ans+=mn*costs[center];
            r-=mn;
            c-=mn;
        }
        if(r||c)
        {
            int mx=max(r,c);
            ll mxCost = mx==r?costs[(center+7)%8]:costs[(center+1)%8];
            ans+=mx*mxCost;
        }
        cout << ans << '\n';
    }


    return 0;
}