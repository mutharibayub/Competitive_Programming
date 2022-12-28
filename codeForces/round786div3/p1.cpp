#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

void testCase()
{
    int x,y;
    cin>>x>>y;
    if(x==y)
    {
        cout<<"1 1\n";
    }
    else if(x>y || y%x)
    {
        cout<<"0 0\n";
    }
    else
    {
        int num=y/x;
        for(int b=2;b<100;b++)
        {
            for(int a=1;pow(b,a)<=num;a++)
            {
                if(pow(b,a)==num)
                {
                    cout<<a<<' '<<b<<'\n';
                    return;
                }
            }
        }
        cout<<"0 0\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase();
    }
    return 0;
}