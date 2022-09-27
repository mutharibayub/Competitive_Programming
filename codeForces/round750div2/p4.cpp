#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int64_t gcd(int64_t a,int64_t b)
{
    if(a<b)
    {
        int t=a;
        a=b;
        b=t;
    }
    return a%b==0?b:gcd(b,a%b);
}

int64_t lcm(int64_t a,int64_t b)
{
    return (a*b)/gcd(a,b);
}

void testCase()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> ans(n);
    bool threePair=n%2==1;
    for(int i=0;i<n;i+=2)
    {
        if(threePair)
        {
            threePair=false;
            int64_t commonNum=lcm(abs(arr[i])+abs(arr[i+1]),abs(arr[i+2]));
            ans[i]=ans[i+1]=commonNum/(abs(arr[i])+abs(arr[i+1]));
            ans[i]*=arr[i]<0?-1:1;
            ans[i+1]*=arr[i+1]<0?-1:1;
            ans[i+2]=(commonNum/arr[i+2])*-1;
            i++;
        }
        else
        {
            int64_t commonNum=lcm(abs(arr[i]),abs(arr[i+1]));
            ans[i]=commonNum/arr[i];
            ans[i+1]=(commonNum/arr[i+1])*-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i)cout<<' ';
        cout<<ans[i];
    }
    cout<<"\n";
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