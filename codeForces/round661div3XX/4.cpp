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
        string s;
        cin>>s;
        vector<int> subs[2];
        vector<int> ans(n);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            int cur = s[i]=='1';
            if(subs[cur^1].size())
            {
                ans[i]=subs[cur^1].back();
                subs[cur].push_back(subs[cur^1].back());
                subs[cur^1].pop_back();
            }
            else
            {
                subs[cur].push_back(++cnt);
                ans[i]=cnt;
            }
        }
        cout << cnt << '\n';
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }

    return 0;
}