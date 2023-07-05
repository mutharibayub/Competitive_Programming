#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
        int n;
        cin>>n;
        if(n==1)
        {
            cout << 1 << '\n';
            continue;
        }

        if(n%2)
        {
            cout << -1 << '\n';
            continue;
        }

        cout << n << ' ' << n-1;
        for(int i=2;i<n;i+=2)
        {
            cout << ' ';
            cout << i << ' ' << n-1-i;
        }cout << '\n';
    }
    return 0;
}