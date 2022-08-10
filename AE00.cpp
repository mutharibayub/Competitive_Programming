#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int64_t count=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                count++;
            }
        }
    }
    cout<<count<<'\n';
    return 0;
}