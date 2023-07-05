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

string PI = "314159265358979323846264338327";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, s, r;
        cin>>n>>s>>r;
        int mx=s-r;
        cout << mx;
        for(int i=0;i<r%(n-1);i++)
        {
            cout << ' ' << r/(n-1)+1;
        }
        for(int i=0;i<n-1-r%(n-1);i++)
        {
            cout << ' ' << r/(n-1);
        }cout << '\n';
    }    

    return 0;
}