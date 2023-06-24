#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
        
        bool ok = !(n%2);
        
        vector<int> cnt(26, 0);
        for(int i=0;i<n&&ok;i++)
        {
            if(++cnt[s[i]-'a']>n/2)ok=false;
        }
        
        if(!ok)
        {
            cout << -1 << '\n';
            continue;
        }

        int ans = 0;
        vector<int> diffCnt(26, 0);
        for(int i=0;i<n/2;i++)
        {
            diffCnt[s[i]-'a'] += s[i]==s[n-i-1];
        }

        priority_queue<int> pq;
        for(int i=0;i<26;i++)if(diffCnt[i])pq.push(diffCnt[i]);

        while(!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            if(pq.empty())
            {
                ans += top;
                break;
            }
            int second = pq.top();
            pq.pop();
            top--, second--;
            ans++;
            if(top)pq.push(top);
            if(second)pq.push(second);
        }

        cout << ans << '\n';

    }
    return 0;
}