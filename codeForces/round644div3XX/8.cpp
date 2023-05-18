#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll toDenary(const string& s)
{
    ll v = 1, out = 0;
    for(int i=s.size()-1;i>=0;i--)
    {
        out += s[i]=='1'?v:0;
        v<<=1;
    }return out;
}

string toBinary(ll num, int fixSize = -1)
{
    string out = "";
    while(num)
    {
        out.push_back('0'+(num&1));
        num>>=1;
    }
    if(fixSize!=-1)while(out.size()<fixSize)out.push_back('0');
    reverse(out.begin(), out.end());
    return out;
}

bool check(vector<ll> &removed, ll num, ll target)
{
    auto iter = lower_bound(removed.begin(), removed.end(), num);
    ll count = iter-removed.begin();
    return num-count<=target;
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
        vector<ll> removed(n);
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            removed[i]=toDenary(s);
        }
        sort(removed.begin(), removed.end());
        ll mx = (1ll<<m)-1;
        ll target = (mx-n)/2;
        ll cur = 0;
        for(ll jmp=mx;jmp;jmp>>=1)
        {
            while(check(removed, cur+jmp, target))cur+=jmp;
        }
        while(1)
        {
            if(*lower_bound(removed.begin(), removed.end(), cur)==cur)cur++;
            else break;
        }
        cout << toBinary(cur, m) << '\n';
    }
    return 0;
}