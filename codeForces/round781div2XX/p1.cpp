#include <iostream>
#include <vector>
using namespace std;

int gcd(int a,int b)
{
    if(a<b)
    {
        int t=a;
        a=b;
        b=t;
    }
    if(a%b)
    {
        return gcd(b,a%b);
    }
    return b;
}

int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}

void testCase()
{
    cout<<lcm(100,20);
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        testCase();
    }
    return 0;
}