#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

vector<int> primes;

int countFactors(int num)
{
    int cnt=0;
    for(auto prime:primes)
    {
        if(1ll*prime*prime>num)break;
        if(num%prime==0)
        {
            while(num%prime==0)
            {
                num/=prime;
                cnt++;
            }
        }
    }return cnt+(num>1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> sieve(int(1e5), true);
    for(int i=2;i<int(1e5);i++)
    {
        if(sieve[i])primes.push_back(i);
        if(sieve[i]&&1ll*i*i<1e5)
        {
            for(int j=i*i;j<1e5;j+=i)
            {
                sieve[j]=false;
            }
        }
    }

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int a, b, k;
        cin>>a>>b>>k;
        if(a>b)swap(a, b);
        bool ok = true;
        if(a==1&&b==1)ok=false;
        else if(k==1)ok = (b%a==0)&&(b!=a);
        else
        {
            int mn=(a!=1)+(b!=1);
            int mx=countFactors(a)+countFactors(b);
            if(k<mn||k>mx)ok=false;
        }
        cout << (ok?"YES":"NO") << '\n';
    }    

    return 0;
}