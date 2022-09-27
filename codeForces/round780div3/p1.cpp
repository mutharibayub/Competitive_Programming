#include <iostream>
#include <vector>
using namespace std;

void testCase()
{
    int a,b;
    cin>>a>>b;
    cout<<(a==0?1:(2*b+a)+1)<<"\n";
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase();
    }

    return 0;
}