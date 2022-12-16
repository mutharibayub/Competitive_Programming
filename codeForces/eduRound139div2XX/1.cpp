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
        int n;
        cin>>n;
        int ans=0;
        while(n>9)
        {
            ans+=9;
            n/=10;
        }
        ans+=n;
        cout << ans << '\n';
    }


    return 0;
}