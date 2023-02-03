#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll getAnswer(const string &a, const string &b, vector<char> &chars, int set)
{
    int chrs[26];
    for(int i=0;i<26;i++)chrs[i]=false;
    for(int i=0;i<chars.size();i++)if(set&(1<<i))chrs[chars[i]-'a']=true;
    ll ans=0;
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==b[i]||chrs[a[i]-'a'])cnt++;
        else if(cnt)
        {
            ans+=1ll*cnt*(cnt+1)/2;
            cnt=0;
        }
    }
    if(cnt)ans+=1ll*cnt*(cnt+1)/2;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        bool chrs[26];
        for(int i=0;i<26;i++)chrs[i]=false;
        for(int i=0;i<n;i++)chrs[a[i]-'a']=true;
        vector<char> chars;
        ll ans=0;
        for(int i=0;i<26;i++)if(chrs[i])chars.push_back(i+'a');
        for(int i=0;i<(1<<chars.size());i++)
        {
            int bitCount=0;
            int tmp=i;
            while(tmp)
            {
                if(tmp%2)bitCount++;
                tmp/=2;
            }
            if(bitCount==min(k, (int)chars.size()))
            {
                ans=max(ans, getAnswer(a, b, chars, i));
            }
        }
        cout << ans << '\n';
    }
}