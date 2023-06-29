#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll out = 1;
    while(e)
    {
        if(e&1)out=(out*n)%MOD;
        n=(n*n)%MOD,e/=2;
    }return out;
}

ll getInv(ll n)
{
    return pwr(n, MOD-2);
}

vector<int> getRotations(const string &s1, const string& s2)
{
    vector<int> out;
    for(int i=0;i<s1.size();i++)
    {
        bool same = true;
        for(int j=0;j<s2.size()&&same;j++)
        {
            if(s1[(i+j)%s1.size()]!=s2[j])same=false;
        }
        if(same)out.push_back(i);
    }
    return out;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out1.txt","w",stdout);

    // int t;
    // cin>>t;
    // while(t--)
    // {
        string s1, s2;
        int n;
        cin>>s1>>s2>>n;

        ll sm = pwr(s1.size()-1, n);
        ll first;

        if(n%2)first=((sm+1)*getInv(s1.size())%MOD + MOD-1 )%MOD;
        else first=(sm + s1.size()-1)*getInv(s1.size())%MOD;

        ll others = (first+(n%2?1:-1))%MOD;

        vector<int> rotations = getRotations(s1, s2);
        
        ll ans = 0;
        
        for(auto rt:rotations)
        {
            if(rt==0)ans=(ans+first)%MOD;
            else ans=(ans+others)%MOD;
        }

        cout << ans << '\n';
    // }

    return 0;
}