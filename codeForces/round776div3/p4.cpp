#include <iostream>
#include <vector>
#include <string>
using namespace std;

void testCase()
{
    int n;
    cin>>n;
    int temp;
    vector<int> dict(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        dict[temp]=i+1;
    }
    vector<int> ans(n+1);
    for(int i=n;i>=1;i--)
    {
        ans[i]=dict[i]%i;
        // if(i==n-1)
        // {
        //     for(int i=1;i<=n;i++)
        //     {
        //         cout<<dict[i]<<" ";
        //     }cout<<endl;
        //     return;
        // }
        for(int j=1;j<=n;j++)
        {
            dict[j]=(dict[j]+(i-ans[i])-1)%i+1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i];
        if(i!=n)cout<<' ';
    }
    cout<<'\n';
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