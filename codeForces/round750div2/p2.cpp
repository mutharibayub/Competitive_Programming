#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int64_t power(int64_t b, int64_t e)
{
    if(e==0)return 1;
    else if(e==1)return b;
    int64_t half=e/2;
    int64_t t=power(b,half);
    return t*t*(e%2==1?b:1);
}

void testCase()
{
    int n;
    cin>>n;
    int64_t ones=0;
    int64_t zeros=0;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t==0)
        {
            zeros++;
        }
        else if(t==1)
        {
            ones++;
        }
    }
    cout<<(ones*int64_t(pow(2,zeros)))<<"\n";
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