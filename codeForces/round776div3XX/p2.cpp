#include <iostream>
#include <vector>
#include <string>
using namespace std;

void testCase()
{
    int l,r,a;
    cin>>l>>r>>a;
    int temp1 = r%a;
    if(temp1+1==a || r-temp1-1<l)
    {
        cout<<(r/a)+temp1<<'\n';
    }
    else
    {
        temp1 = r-temp1-1;
        cout<<(temp1/a)+temp1%a<<'\n';
    }
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