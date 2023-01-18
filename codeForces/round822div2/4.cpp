#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        k--;
        vector<int64_t> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(k==0 || k==n-1)
        {
            cout << "YES\n";
            continue;
        }
        int l=k,r=k;
        int64_t curSum = a[k];
        while(l>0 && r<n-1)
        {
            bool found = false;
            int64_t prevSum = curSum;
            int64_t maxSum = curSum;
            int maxSumInd = l;
            for(int i=l-1;i>=0;i--)
            {
                if(curSum+a[i]>=0)
                {
                    curSum+=a[i];
                }
                else
                {
                    break;
                }
                if(curSum > maxSum)
                {
                    maxSum = curSum;
                    maxSumInd = i;
                }
                if(i==0)found=true;
            }
            if(found)
            {
                l=0;
                break;
            }
            l = maxSumInd;
            curSum = maxSum;
            maxSumInd = r;
            for(int i=r+1;i<n;i++)
            {
                if(curSum+a[i]>=0)
                {
                    curSum+=a[i];
                }
                else
                {
                    break;
                }
                if(curSum > maxSum)
                {
                    maxSum = curSum;
                    maxSumInd = i;
                }
                if(i==n-1)
                {
                    found=true;
                }
            }
            if(found)
            {
                r=n-1;
                break;
            }
            r = maxSumInd;
            curSum = maxSum;
            if(prevSum==curSum)
            {
                break;
            }
        }
        if(l==0 || r==n-1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}