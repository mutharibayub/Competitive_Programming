#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll calcWood(const vector<ll> heights, ll height)
{
    ll wood = 0;
    for(int i=0;i<heights.size();i++)
    {
        wood += (heights[i]<height?0:heights[i]-height);
    }
    return wood;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin>>n>>m;
    vector<ll> heights(n);
    for(int i=0;i<n;i++)cin>>heights[i];

    ll cutHeight = 0;
    for(ll jump=1e9;jump>0;jump=jump>>1)
    {
        while(calcWood(heights, cutHeight+jump)>=m)cutHeight += jump;
    }

    cout<<cutHeight<<'\n';

    return 0;
}