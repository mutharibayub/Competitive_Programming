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
        int n;
        cin>>n;
        int mx=-(1e9+7), mn=1e9+7;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            mx=max(mx, num);
            mn=min(mn, num);
        }
        cout << mx-mn << '\n';
    }    

    return 0;
}