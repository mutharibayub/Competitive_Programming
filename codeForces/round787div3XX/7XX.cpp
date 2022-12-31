#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 250+1;
const int M = 250+1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    int dp[N][N][M];
    for(int i=0;i<=m;i++)
    {
        if(arr[0]>=i)dp[0][i][i]=arr[0]-i;
        else arr[]
    }

    return 0;
}