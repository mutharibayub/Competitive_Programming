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

ll GCD(ll a, ll b)
{
    if(b>a)swap(a, b);
    if(!b)return a;
    return GCD(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        ll oddGCD=arr[1], evenGCD=arr[0];
        for(int i=2;i<n;i++)
        {
            if(i%2)oddGCD=GCD(oddGCD, arr[i]);
            else evenGCD=GCD(evenGCD, arr[i]);
        }
        bool evenOk=true, oddOk=true;
        for(int i=0;i<n;i++)
        {
            if(i%2)oddOk&=(arr[i]%evenGCD!=0);
            else evenOk&=(arr[i]%oddGCD!=0);
        }
        if(evenOk)cout << oddGCD << '\n';
        else if(oddOk)cout << evenGCD << '\n';
        else cout << 0 << '\n';
    }    

    return 0;
}