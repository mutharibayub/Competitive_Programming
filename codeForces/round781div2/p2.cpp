#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void testCase()
{
    unordered_map<int,int> c;
    int maxFreq=1;
    int n;
    cin>>n;
    int inp;
    for(int i=0;i<n;i++)
    {
        cin>>inp;
        if(c.find(inp)!=c.end())
        {
            c[inp]++;
        }
        else
        {
            c[inp]=1;
        }
        maxFreq=max(maxFreq,c[inp]);
    }
    int steps=0;
    while(maxFreq<n)
    {
        steps+=min(n-maxFreq,maxFreq)+1;
        maxFreq*=2;
    }
    cout<<steps<<endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        // cout<<"Case #"<<i+1<<": ";
        testCase();
    }
    return 0;
}