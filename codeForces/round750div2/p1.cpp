#include <iostream>
#include <vector>
using namespace std;

void testCase()
{
    int64_t a,b,c;
    cin>>a>>b>>c;
    cout<<(a+b*2+c*3)%2<<"\n";

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