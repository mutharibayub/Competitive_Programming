#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        if(n==a && a==b)
        {
            cout << "YES\n";
            continue;
        }
        cout << (a+b<n-1?"YES":"NO") << '\n';
    }

    return 0;
}