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
        string s;
        cin>>n>>s;
        vector<int> cnt(7*7, 0);
        int ans = 0;
        for(int i=0;i+1<n;i++)
        {
            if(!cnt[(s[i]-'a')*7+(s[i+1]-'a')]++)
            {
                ans++;
            }
        }cout << ans << '\n';
    }
    return 0;
}