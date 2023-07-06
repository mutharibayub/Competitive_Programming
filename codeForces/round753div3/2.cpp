#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        ll x,  n;
        cin>>x>>n;
        for(int i=0;i<n%4;i++)
        {
            x += (x%2?1:-1)*(n/4*4+i+1);
        }
        cout << x << '\n';
    }    

    return 0;
}