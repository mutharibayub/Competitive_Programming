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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int c[3][2];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                cin>>c[i][j];
            }
        }
        if(c[0][1]==c[1][1])
        {
            for(int i=0;i<3;i++)
            {
                swap(c[i][0],c[i][1]);
            }
        }
        int base = 0;
        if(c[0][0]==c[1][0]&&c[0][0]==c[2][0]
        &&abs(c[0][1]-c[2][1])<abs(c[0][1]-c[1][1])
        &&abs(c[1][1]-c[2][1])<abs(c[1][1]-c[0][1]))base += 2;
        cout << base + abs(c[0][0]-c[1][0]) + abs(c[0][1]-c[1][1]) << '\n';
    }    

    return 0;
}