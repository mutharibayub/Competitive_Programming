#include <iostream>
#include <vector>
using namespace std;

int lg2n(int n)
{
    int i=1;
    int c=0;
    while(i*2<n)
    {
        i*=2;
        c++;
    }
    return c;
}

void getMin(vector<int>& dp, int s,int e)
{
    int a=e-s+1;
    for(int i=0;i<30;i++)
    {

    }
}

void testCase()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(lg2n(n),-1));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=arr[i];
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        testCase();
    }
    return 0;
}