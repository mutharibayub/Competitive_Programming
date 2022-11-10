#include <iostream>
#include <vector>
#include <string>
using namespace std;

void testCase()
{
    int n,d;
    cin>>n>>d;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> gaps(n+1);
    int meu=arr.front()-1;
    int meuInd=0;
    int maxGap=2*(arr.front()-1);
    gaps.front()=arr.front()-1;
    gaps.back()=d-arr.back();
    maxGap=max((d-arr.back())*2,maxGap);
    cout<<"max gap: "<<maxGap<<'\n';
    if(n==2)
    {
        if(d<=3)
        {
            cout<<"0\n";
            return;
        }
        if(abs(arr[0]-d/2)<abs(arr[1]-d/2))
        {
            cout<<((arr[0]+1)/2)<<'\n';
        }
        else
        {
            cout<<arr[1]-1<<'\n';
        }
        return;
    }
    for(int i=1;i<n;i++)
    {
        gaps[i]=arr[i]-arr[i-1]-1;
        maxGap=max(maxGap,gaps[i]);
        if(meu>gaps[i])
        {
            meu=gaps[i];
            meuInd=i;
        }
    }
    // cout<<"meu: "<<meu<<'\n';
    // cout<<"meuInd: "<<meuInd<<'\n';
    int ans=meu;
    if(meuInd==0)
    {
        int minGap=(gaps[0]+gaps[1])/2;
        // cout<<minGap<<'\n';
        for(int i=2;i<n;i++)
        {
            minGap=min(minGap,gaps[i]);
        }
        ans=max(ans,minGap);
        minGap = gaps[0]+gaps[1]+1;
        for(int i=2;i<n;i++)
        {
            minGap=min(minGap,gaps[i]);
        }
        minGap=min(minGap,(maxGap-1)/2);
        ans=max(ans,minGap);
    }
    else if(meuInd==n-1)
    {
        int minGap=gaps[n]+gaps[n-1];
        for(int i=n-2;i>=0;i--)
        {
            minGap=min(minGap,gaps[i]);
        }
        ans=max(ans,minGap);
        minGap = gaps[n]+gaps[n-1]+1;
                // cout<<"minGap: "<<minGap<<'\n';
        for(int i=n-2;i>=0;i--)
        {
            minGap=min(minGap,gaps[i]);
        }
        minGap=min(minGap,(maxGap-1)/2);
        ans=max(ans,minGap);
    }
    else
    {
        int minGap = (gaps[meuInd]+gaps[meuInd-1])/2;
        for(int i=0;i<n;i++)
        {
            if(i!=meuInd && i!=meuInd-1)
            {
                minGap=min(minGap,gaps[i]);
            }
        }
        ans=max(ans,minGap);
        minGap = gaps[meuInd]+gaps[meuInd-1]+1;
        for(int i=0;i<n;i++)
        {
            if(i!=meuInd && i!=meuInd-1)
            {
                minGap=min(minGap,gaps[i]);
            }
        }
        minGap=min(minGap, (maxGap-1)/2);
        ans=max(ans,minGap);
        minGap = (gaps[meuInd]+gaps[meuInd+1])/2;
        for(int i=0;i<n;i++)
        {
            if(i!=meuInd && i!=meuInd+1)
            {
                minGap=min(minGap,gaps[i]);
            }
        }        
        ans=max(ans,minGap);
        minGap = gaps[meuInd]+gaps[meuInd+1]+1;
        for(int i=0;i<n;i++)
        {
            if(i!=meuInd && i!=meuInd+1)
            {
                minGap=min(minGap,gaps[i]);
            }
        }
        minGap=min(minGap, (maxGap-1)/2);
        ans=max(ans,minGap);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--)
    {
        testCase();
    }

    return 0;
}