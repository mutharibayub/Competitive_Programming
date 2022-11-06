#include <iostream>
#include <vector>
#include <array>
using namespace std;

#define ll long long

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
        cout << (n+1)/2 << '\n';
        for(int i=0;i<(n+1)/2;i++)
        {
            cout << (3*i+2) << ' ' << (n*3-i*3) << '\n';
        }
    }

    return 0;
}