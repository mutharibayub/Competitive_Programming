#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
        int n;
        cin>>n;
        ll largest[4] = {-1,-1,-1,-1};
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            if(num>0)
            {
                if(num>largest[1])largest[1]=num;
                if(largest[1]>largest[0])swap(largest[0], largest[1]);
            }
            else 
            {
                num*=-1;
                if(num>largest[3])largest[3]=num;
                if(largest[3]>largest[2])swap(largest[2], largest[3]);
            }
        } 
        ll ans = -1e18;
        for(int i=0;i<4;i++)
        {
            if(largest[i]!=-1)
            for(int j=i+1;j<4;j++)
            {
                if(largest[j]==-1)continue;
                int num1=largest[i]*(i<2?1:-1);
                int num2=largest[j]*(j<2?1:-1);
                ans = max(ans, 1ll*num1*num2);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}