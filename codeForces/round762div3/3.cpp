#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string a,s,b="";
        cin>>a>>s;
        reverse(a.begin(),a.end());
        reverse(s.begin(),s.end());
        int sptr=0,aptr=0;
        bool ok=true;
        while(sptr<s.size()&&ok)
        {
            int an = aptr<a.size()?(a[aptr]-'0'):0;
            if(s[sptr]-'0'>=an)
            {
                b.push_back(s[sptr]-an);
                sptr++;
            }
            else
            {
                if(sptr+1<s.size())
                {
                    int sn = (s[sptr+1]-'0')*10+s[sptr]-'0';
                    if(sn>=20||sn<an)
                    {
                        ok=false;
                    }
                    else
                    {
                        b.push_back(sn-an+'0');
                        sptr+=2;
                    }
                }
                else
                {
                    ok=false;
                }
            }
            aptr++;
        }
        if(ok&&aptr>=a.size())
        {
            while(b.size()>1&&b.back()=='0')b.pop_back();
            reverse(b.begin(),b.end());
            cout << b << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }

    return 0;
}