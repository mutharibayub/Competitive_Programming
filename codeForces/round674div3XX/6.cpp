#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9+7;
const int N = 2e5+1;

typedef long long ll;

ll pow3[N];
ll digC[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pow3[0]=1, digC[0]=0;
    for(int i=1;i<N;i++)
    {
        pow3[i]=pow3[i-1]*3%MOD;
        digC[i]=(digC[i-1]*3%MOD+pow3[i-1])%MOD;
    }

    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> lq(n), la(n), rq(n), rc(n);
    lq[0]=0, la[0]=0, rq[n-1]=0, rc[n-1]=0;
    for(int i=1;i<n;i++)
    {
        lq[i]=lq[i-1]+(s[i-1]=='?');
        la[i]=la[i-1]+(s[i-1]=='a');
    }
    for(int i=n-2;i>=0;i--)
    {
        rq[i]=rq[i+1]+(s[i+1]=='?');
        rc[i]=rc[i+1]+(s[i+1]=='c');
    }
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='b'||s[i]=='?')
        {
            ll left = (la[i]*pow3[lq[i]]%MOD+digC[lq[i]])%MOD;
            ll right = (rc[i]*pow3[rq[i]]%MOD+digC[rq[i]])%MOD;
            ans = (ans+left*right%MOD)%MOD;
        }
    }
    cout << ans << '\n';

    return 0;
}