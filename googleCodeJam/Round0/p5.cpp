#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void testCase()
{
    int n,k;
    cin>>n>>k;
    int64_t trimDown = (n*(n-1))/2;
    int64_t buildUp = n-1;
    for(int i=0;i<k+1;i++)
    {
        
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