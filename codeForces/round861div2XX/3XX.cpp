#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

int getLucky(ll n, ll mn=10, ll mx = -1)
{
    while(n)
    {
        mn=min(mn, n%10);
        mx=max(mx, n%10);
        n/=10;
    }
    return mx-mn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string l, r;
        cin>>l>>r;
        if(r.size()-l.size()>=2)
        {
            cout << string(l.size()+1, '1') << '\n';
            continue;
        }
        ll ln=stoll(l), rn=stoll(r);
        if(rn<=1000)
        {
            int mn=10, num = -1;
            for(int i=ln;i<=rn;i++)
            {
                int tmp = getLucky(i);
                if(tmp<mn)
                {
                    mn = tmp;
                    num = i;
                }
                if(mn == 0)break;
            }
            cout << num << '\n';
            continue;
        }
        reverse(l.begin(), l.end());
        while(l.size()<r.size())l.push_back('0');
        reverse(l.begin(), l.end());
        string num1="", num2="", eqs = "";
        bool eq = true;
        bool start = false;
        int left = 0;
        for(int i=0;i<l.size();i++)
        {
            if(r[i]!=l[i])eq=false;
            if(l[i]!='0')start=true;
            if(eq)
            {
                eqs.push_back(l[i]);
            }
            else
            {
                num1.push_back(r[i]);
                if(start)num2.push_back(l[i]);
                if(num2.size()==2)
                {
                    left = l.size()-(i+1);
                    break;
                }
            }
        }
        int mxx = -1, mnn = 10;
        for(int i=0;i<eqs.size();i++)
        {
            mxx = max(mxx, eqs[i]-'0');
            mnn = min(mnn, eqs[i]-'0');
        } 
        if(num1.size()==0)
        {
            cout << stoll(eqs) << '\n';
            continue;
        }
        ll n1 = stoll(num1), n2 = stoll(num2);
        assert(n1>=n2);
        int mn = 10, num = -1;
        for(ll i=n2;i<=n1;i++)
        {
            int tmp = getLucky(i, mnn, mxx);
            if(tmp<mn)
            {
                mn = tmp;
                num = i;
            }
        }
        string ans = eqs + to_string(num);
        if(left>0)ans += string(left, ans.back());
        cout << ans << '\n';
    }
    return 0;
}