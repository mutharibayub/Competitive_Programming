#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        string s;
        cin>>n>>k>>s;
        vector<int> arr(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=s[i]=='W';
            arr[i]=sum;
        }
        int ans=1e9+7;
        for(int i=0;i+k-1<n;i++)
        {
            ans=min(ans, arr[i+k-1]-(i-1<0?0:arr[i-1]));
        }
        cout << ans << '\n';
    }

    return 0;
}