#include <iostream>
#include <string>
#include <climits>
using namespace std;

void testCase()
{
    int c[3][4];
    int min[4]={INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>c[i][j];
            if(c[i][j]<min[j])
            {
                min[j]=c[i][j];
            }
        }
    }
    int sum = 0;
    for(int i=0;i<4;i++)
    {
        sum += min[i];
    }
    if(sum<1000000)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        sum=0;
        for(int i=0;i<4;i++)
        {
            if(sum>=1000000)
            {
                cout<<"0";
            }
            else
            {
                if(sum+min[i]>1000000)cout<<1000000-sum;
                else cout<<min[i];
                sum+=min[i];
            }
            if(i==3)cout<<'\n';
            else cout<<' ';
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case #"<<to_string(i+1)<<": ";
        testCase();
    }
    return 0;
}