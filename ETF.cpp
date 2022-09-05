#include <iostream>
using namespace std;

int ETF(int n)
{
    int result = n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n /= i;
            }
            result -= result/i;
        }
    }
    if(n>1)
    {
        result -= result/n;
    }
    return result;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n=0;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<ETF(n)<<'\n';
    }


    return 0;
}