#include <iostream>
#include <vector>

using namespace std;

int GCD(int x, int y)
{
    if(x<y)swap(x,y);
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
        int n,d;
        cin>>n>>d;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<bool> done(n,false);
        int cycleLength = n/GCD(n,d);
        bool ok = true;
        int mxConsecOnes = 0;
        for(int i=0;i<n&&ok;i++)
        {
            if(!done[i])
            {
                int iter=i;
                int zeroInd = -1;
                int ones = 0;
                for(int j=0;j<cycleLength&&zeroInd==-1;j++)
                {
                    int ind = (iter+j*1ll*d)%n;
                    if(arr[ind]==0)
                    {
                        zeroInd=ind;
                    }
                }
                if(zeroInd==-1)
                {
                    ok=false;
                }
                else
                {
                    for(int j=0;j<cycleLength;j++)
                    {
                        int ind = (zeroInd+j*1ll*d)%n;
                        done[ind]=true;
                        if(arr[ind])ones++;
                        else ones=0;
                        mxConsecOnes = max(mxConsecOnes,ones);
                    }
                }
            }
        }
        if(!ok)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << mxConsecOnes << '\n';
        }
    }

    return 0;
}