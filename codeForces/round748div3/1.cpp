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
        int a, b, c;
        cin>>a>>b>>c;
        cout << max(0,max(b,c)-a+1) << ' ' << max(0,max(a,c)-b+1) << ' ' << max(0,max(a,b)-c+1) << '\n'; 
    }    

    return 0;
}