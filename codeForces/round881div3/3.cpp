#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) 
    {
        ll n;
        cin>>n;
        ll sum = 0;
        while(n)
        {
            sum+=n;
            n/=2;
        }
        cout << sum << '\n';
    }
    return 0;
}