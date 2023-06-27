#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool MULTI = true;
    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        long long n, k, g;
        cin>>n>>k>>g;
        long long assign = (g-1)/2*n;
        cout << min(k*g, assign/g*g) << '\n';
    }
    return 0;
}