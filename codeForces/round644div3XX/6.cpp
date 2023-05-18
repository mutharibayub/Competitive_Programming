#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool check(const string& s, vector<string> &strings)
{
    for(int i=1;i<strings.size();i++)
    {
        int cnt = 0;
        for(int j=0;j<strings[i].size();j++)
        {
            if(s[j]!=strings[i][j]&&++cnt==2)return false;
        }
    }return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<string> strings(n);
        for(int i=0;i<n;i++)cin>>strings[i];
        vector<set<char>> chars(m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                chars[j].insert(strings[i][j]);
            }
        }
        bool found = false;
        string ans = strings.front();
        for(int i=0;i<m&&!found;i++)
        {
            for(auto c:chars[i])
            {
                char tmp = ans[i];
                ans[i]=c;
                if(check(ans, strings))
                {
                    found = true;
                    break;
                }
                ans[i]=tmp;
            }
        }
        if(found)cout << ans << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}