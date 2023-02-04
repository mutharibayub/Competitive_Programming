#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>

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
        int cnt1[26],cnt2[26];
        for(int i=0;i<26;i++)cnt1[i]=cnt2[i]=0;
        int dCount1=0,dCount2=0;

        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(!cnt1[s[i]-'a']++)
            {
                dCount1++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans, dCount1+dCount2);
            if(!cnt2[s[i]-'a']++)
            {
                dCount2++;
            }
            if(!(--cnt1[s[i]-'a']))
            {
                dCount1--;
            }
        }
        cout << ans << '\n';
    }

    return 0;

}