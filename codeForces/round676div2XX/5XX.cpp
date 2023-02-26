#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define inf 1e18+7

struct node
{
    ll mnEven=inf;
    ll mxEven=-inf;
    ll mnOdd=inf;
    ll mxOdd=-inf;
    ll mnAns=inf;
    ll mxAns=-inf;
};

#define doMin(a,b) a=min(a,b);
#define doMax(a,b) a=max(a,b);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<node> dp(n);
    dp[0].mnOdd = -arr.front();
    dp[0].mxOdd = -arr.front();
    dp[0].mnAns = arr.front();
    dp[0].mxAns = arr.front();
    for(int i=1;i<n;i++)
    {
        if(dp[i-1].mnEven!=inf)
        {
            doMin(dp[i].mnAns, dp[i-1].mnEven+arr[i]);
            doMin(dp[i].mnOdd, dp[i-1].mnEven-arr[i]);
        }
        if(dp[i-1].mxEven!=-inf)
        {
            doMax(dp[i].mxAns, dp[i-1].mxEven+arr[i]);
            doMax(dp[i].mxOdd, dp[i-1].mxEven-arr[i]);
        }
        if(dp[i-1].mnOdd!=inf)
        {
            doMin(dp[i].mnAns, dp[i-1].mnOdd-arr[i]);
            doMin(dp[i].mnEven, dp[i-1].mnOdd+arr[i]);
        }
        if(dp[i-1].mxOdd!=-inf)
        {
            doMax(dp[i].mxAns, dp[i-1].mxOdd-arr[i]);
            doMax(dp[i].mxEven, dp[i-1].mxOdd+arr[i]);
        }  
        doMin(dp[i].mnOdd, -dp[i].mxAns);
        doMax(dp[i].mxOdd, -dp[i].mnAns); 
        doMin(dp[i].mnEven, -dp[i-1].mxAns+arr[i]);
        doMax(dp[i].mxEven, -dp[i-1].mnAns+arr[i]);
    }

    cout << dp.back().mxAns << '\n';


    return 0;
}