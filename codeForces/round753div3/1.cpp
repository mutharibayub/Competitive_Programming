#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        string s;
        vector<int> loc(26);
        cin>>s;
        for(int i=0;i<26;i++)
        {
            loc[s[i]-'a']=i;
        }
        cin>>s;
        int ans = 0;
        for(int i=0;i+1<s.size();i++)
        {
            ans += abs(loc[s[i]-'a']-loc[s[i+1]-'a']);
        }
        cout << ans << '\n';
    }    

    return 0;
}