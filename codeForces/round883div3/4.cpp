#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;

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
        int n, d, h;
        cin>>n>>d>>h;
        set<int> heights;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            heights.insert(num);
        }
        double fullArea = 0.5*d*h;
        int last = -1e9;
        double sum = fullArea*heights.size();
        for(auto height: heights)
        {
            if(height-last<h)
            {
                double ratio = double(h-height+last)/h;
                sum -= ratio*ratio*fullArea;
            }
            last = height;
        }
        cout << setprecision(15) << sum << '\n';
    }    

    return 0;
}