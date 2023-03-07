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
        string s;
        cin>>s;
        vector<int> cnt(26, 0);
        int ansLen=0;
        for(int i=0;i<s.size();i++)
        {
            ansLen += (cnt[s[i]-'a']==0);
            cnt[s[i]-'a']++;
        }
        string ans(ansLen, ' ');
        int last = 0;
        vector<bool> done(26, false);
        for(int i=0;i<ansLen;i++)
        {
            vector<int> tmpCnt = cnt;
            vector<int> possible(26, 1e9+7);
            for(int j=0;j<last;j++)tmpCnt[s[j]-'a']--;
            for(int j=last;j<s.size();j++)
            {
                if(!done[s[j]-'a'])
                {
                    possible[s[j]-'a']=min(possible[s[j]-'a'], j);
                    tmpCnt[s[j]-'a']--;
                    if(tmpCnt[s[j]-'a']==0)break;
                }
            }
            char c = ' ';
            for(int j=25;j>=0;j--)
            {
                if(possible[j]!=1e9+7)
                {
                    c = j+'a';
                    done[j]=true;
                    last=possible[j]+1;
                    break;
                }
            }
            ans[i]=c;
        }
        cout << ans << '\n';
    }

    return 0;
}