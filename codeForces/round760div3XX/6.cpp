#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool checkString(const string &a, const string &b)
{
    if(a.size()>b.size())return false;
    for(int i=0;i+a.size()-1<b.size();i++)
    {
        bool match=true;
        for(int j=0;j<a.size()&&match;j++)
        {
            if(a[j]!=b[i+j])match=false;
        }
        for(int j=0;j<i&&match;j++)
        {
            if(b[j]!='1')match=false;
        }
        for(int j=i+a.size();j<b.size()&&match;j++)
        {
            if(b[j]!='1')match=false;
        }
        if(match)return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout << "YES" << '\n';
    }
    else if(b%2==0)
    {
        cout << "NO" << '\n';
    }
    else
    {
        string as, bs;
        for(ll tmp=a;tmp;tmp/=2)
        {
            if(tmp%2)as.push_back('1');
            else as.push_back('0');
        }
        for(ll tmp=b;tmp;tmp/=2)
        {
            if(tmp%2)bs.push_back('1');
            else bs.push_back('0');
        }
        reverse(as.begin(),as.end());
        reverse(bs.begin(),bs.end());
        string as1=as;
        while(as1.back()=='0')as1.pop_back();
        bool ans = checkString(as,bs);
        ans |= checkString(as1,bs);
        reverse(as.begin(),as.end());
        reverse(as1.begin(),as1.end());
        ans |= checkString(as,bs);
        ans |= checkString(as1,bs);
        cout << (ans?"YES":"NO") << '\n';
    }

    return 0;
}