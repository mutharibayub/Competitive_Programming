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
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1, 0);
    }
    int get(int idx)
    {
        idx++;
        int o=0;
        while(idx)
        {
            o+=arr[idx];
            idx-=idx&-idx;
        }return o;
    }
    void update(int idx, int update)
    {
        idx++;
        while(idx<arr.size())
        {
            arr[idx]+=update;
            idx+=idx&-idx;
        }
    }
};

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

// const int N = 2e5+1;
// const int MOD = 998244353;
// ll fact[N];
// ll factInv[N];
// ll nCr(ll n, ll r)
// {
//     return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
// }
// ll pwr(ll b, ll e)
// {
//     ll o=1;
//     while(e)
//     {
//         if(e&1)o=(o*b)%MOD;
//         b=(b*b)%MOD;
//         e/=2;
//     }return o;
// }
// ll getInv(ll n)
// {
//     return pwr(n, MOD-2);
// }
// void initFact()
// {
//     fact[0]=1;
//     for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
//     factInv[N-1]=getInv(fact[N-1]);
//     for(int i=N-2;i>=0;i--)factInv[i]=(factInv[i+1]*(i+1))%MOD;
// }

int getParent(vector<int> &parent, int u)
{
    if(parent[parent[u]]!=parent[u])
    {
        parent[u]=getParent(parent, parent[u]);
    }return parent[u];
}

vector<int> primes;

void updateD(map<int, int> &primeDivisors, int &d, int toAdd)
{
    for(auto prime: primes)
    {
        if(prime*prime>toAdd)
            break;
        if(toAdd%prime==0)
        {
            while(toAdd%prime==0)
            {
                d/=primeDivisors[prime]+1;
                primeDivisors[prime]++;
                d*=primeDivisors[prime]+1;
                toAdd/=prime;
            }
        }
    }
    if(toAdd>1)
    {
        d/=primeDivisors[toAdd]+1;
        primeDivisors[toAdd]++;
        d*=primeDivisors[toAdd]+1;
    }
}

bool divisible(map<int, int> &primeDivisors, int d)
{
    map<int, int> pDivisors;
    for(auto prime: primes)
    {
        if(prime*prime>d)
            break;
        if(d%prime==0)
        {
            while(d%prime==0)
            {
                pDivisors[prime]++;
                d/=prime;
            }
        }
    }
    if(d>1)pDivisors[d]++;
    for(auto [divisor, count]: pDivisors)
    {
        int mn = primeDivisors.find(divisor)==primeDivisors.end()?0:primeDivisors[divisor];
        if(count > mn)
            return false;
    }return true;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> sieve(1e6+1, true);
    for(int i=2;i*i<1e6+1;i++)
    {
        if(sieve[i])
        {
            primes.push_back(i);
            for(int j=i*i;j<1e6+1;j+=i)
            {
                sieve[j]=false;
            }
        }
    }

    // initFact();

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, q;
        cin>>n>>q;

        int tmp=n;
        map<int, int> primeDivisors;
        int d=1;
        updateD(primeDivisors, d, n);
        auto initVal = primeDivisors;

        for(int i=0;i<q;i++)
        {
            int k;
            cin>>k;
            if(k==1)
            {
                int x;
                cin>>x;
                updateD(primeDivisors, d, x);
                cout << (divisible(primeDivisors, d)?"YES":"NO") << '\n';
            }
            else
            {
                n=tmp;
                d=1;
                primeDivisors = map<int, int>();
                updateD(primeDivisors, d, n);
            }
        }

    }
    return 0;
}