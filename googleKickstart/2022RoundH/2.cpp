#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5+1;

ll dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    for(int i=1;i<N;i++)dp[i]=i;
    for(int i=2;i<N;i++)
    {
        dp[i]=min(dp[i], dp[i-1]+1);
        for(int j=i+i;j<N;j+=i)
        {
            dp[j]=min(dp[j], dp[i]+4ll+(2*(j-i)/i));
        }
    }

    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int L;
        cin>>L;
        cout << "Case #" << t << ": " << dp[L] << '\n';
    }   


    return 0;
}