#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5+1;
const int logN = 20;

int sparseTable[2*N][logN];

int GCD(int x, int y)
{
    if(x<y)swap(x,y);
    if(!y)return x;
    return GCD(y, x%y);
}

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
        for(int i=0;i<n;i++)
        {
            cin>>sparseTable[i][0];
            sparseTable[n+i][0]=sparseTable[i][0];
        }
        for(int i=1;(1<<i)<=2*n;i++)
        {
            for(int j=0;j+(1<<i)<=2*n;j++)
            {
                sparseTable[j][i]=GCD(sparseTable[j][i-1], sparseTable[j+(1<<(i-1))][i-1]);
            }
        }
        int goal=-1;
        int idx=0;
        for(int jump=logN;jump>=0;jump--)
        {
            while(idx+(1<<jump)<=n)
            {
                goal=(goal==-1?sparseTable[idx][jump]:GCD(goal, sparseTable[idx][jump]));
                idx+=(1<<jump);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int size=0;
            int val=sparseTable[i][0];
            if(val==goal)ans=max(ans, 0);
            else
            {
                int tmp;
                for(int jump=logN;jump>=0;jump--)
                {
                    while(size+(1<<jump)<=n&&(tmp=GCD(val, sparseTable[i+size][jump]))!=goal)
                    {
                        size+=(1<<jump);
                        val=tmp;
                    }
                }
                ans=max(ans, size);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}