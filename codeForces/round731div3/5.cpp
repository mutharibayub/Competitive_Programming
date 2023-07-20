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
        int n, k;
        cin>>n>>k;
        vector<int> tempr(n, 1e9+1e8+7);
        vector<int> ac(n, 1e9+7);
        vector<int> acInd(k);
        for(int i=0;i<k;i++)
        {
            cin>>acInd[i];
            --acInd[i];
        }
        for(int i=0;i<k;i++)
        {
            int tmp;
            cin>>tmp;
            ac[acInd[i]]=min(ac[acInd[i]], tmp);
        }
        int temp=-1;
        for(int i=0;i<n;i++)
        {
            if(ac[i]!=1e9+7)temp=(temp==-1?ac[i]:min(temp, ac[i]));
            if(temp!=-1)
            {
                tempr[i]=min(tempr[i], temp);
            }
            if(temp!=-1)temp++;
        }
        temp=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(ac[i]!=1e9+7)temp=(temp==-1?ac[i]:min(temp, ac[i]));
            if(temp!=-1)
            {
                tempr[i]=min(tempr[i], temp);
            }
            if(temp!=-1)temp++;
        }
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << tempr[i];
        }cout << '\n';
    }

    return 0;
}