#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;

#define tst int tttt;cin>>tttt;while(tttt--)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    tst
    {
        int n, d;
        cin>>n>>d;
        string s;
        cin>>s;
        string ans = "";
        bool done=false;
        for(int i=0;i<n;i++)
        {
            if(!done&&(s[i]-'0')<d)
            {
                ans.push_back(d+'0');
                done=true;
            }
            ans.push_back(s[i]);
        }
        if(!done)ans.push_back(d+'0');
        cout << ans << '\n';
    }

    return 0;
}