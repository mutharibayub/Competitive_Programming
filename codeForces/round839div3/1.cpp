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
        string s;
        cin>>s;
        int ans=s[0]+s[2]-2*'0';
        cout << ans << '\n';
    }

    return 0;
}