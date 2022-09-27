#include <iostream>
#include <vector>
using namespace std;

void testCase()
{
    int n;
    cin>>n;
    string num="";
    int tPairs=n/3;
    int leftover=n%3;
    if(leftover==1)
    {
        num.push_back('1');
    }
    for(int i=0;i<tPairs;i++)
    {
        num.push_back('2');
        num.push_back('1');
    }
    if(leftover==2)
    {
        num.push_back('2');
    }
    cout<<num<<"\n";
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