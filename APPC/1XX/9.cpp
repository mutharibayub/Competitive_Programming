#include <iostream>
#include <vector>

using namespace std;

int64_t power(int64_t num, int64_t exp, int64_t mod)
{
    int64_t ans = 1;
    while(exp)
    {
        if(exp&1)
        {
            ans=(ans*num)%mod;
        }
        num = (num*num)%mod;
        exp = exp>>1;
    }
    return ans;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> arr(n), closing(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    int last = -1;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='>')
        {
            last=i;
        }
        else
        {
            closing[i] = last;
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='<')
        {
            last=i;
        }
        else
        {
            closing[i] = last;
        }
    }

    vector<int64_t> ans(n,0);

    for(int i=0;i<n;i++)
    {
        int startPos = i;
        int len = -1;
        int sub = 0;
        if(closing[closing[i]]==i)
        {
            len = abs(closing[i]-i)*2;
        }
        else
        {
            sub = abs(closing[i]-i);
            len = abs(closing[closing[i]]-closing[i])*2;
            startPos = closing[i];
        }
        int pos = power(10,100,len);
        pos = ((pos-sub)+100000*len)%len;
        if(pos>abs(closing[startPos]-startPos))
        {
            pos = abs(closing[startPos]-startPos)-pos;
        }
        if(s[startPos]=='>')
        {
            startPos+=pos;
        }
        else
        {
            startPos-=pos;
        }
        ans[startPos]+=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i)cout << ' ';
        cout << ans[i];
    }cout << '\n';
    return 0;
}