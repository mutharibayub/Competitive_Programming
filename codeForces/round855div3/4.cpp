#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

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
        string s;
        cin>>s;
        int ans = 1;
        for(int i=0;i+2<n;i++)
        {
            if(s[i+2]!=s[i])ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}