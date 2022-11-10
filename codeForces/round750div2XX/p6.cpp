#include <iostream>
#include <vector>
using namespace std;

#define maxVal 500

int main()
{
    int lim=0;
    while(1<<lim<maxVal)
    {
        lim++;
    }
    lim = 1<<lim;
    vector<int> xors(lim,-1);
    xors[0]=1e9+7;

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<lim;j++)
        {
            if(xors[j]>arr[i])
            {
                if(xors[j^arr[i]]==-1)count++;
                xors[j^arr[i]]=max(xors[j^arr[i]],arr[i]);
            }
        }
    }
    cout<<count<<'\n';
    for(int i=0;i<lim;i++)
    {
        if(xors[i]==-1)continue;
        if(i)
        {
            cout<<' ';
        }
        cout<<i;
    }cout<<'\n';

    return 0;
}