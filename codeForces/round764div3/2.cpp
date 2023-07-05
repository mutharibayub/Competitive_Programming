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
        bool ok = ((b+b-a)%c==0&&(b+b-a)/c>0)||
                ((b+b-c)%a==0&&(b+b-c)/a>0)||
                ((c-a)%2==0&&(a+(c-a)/2)%b==0&&(a+(c-a)/2)/b>0);
        cout << (ok?"YES":"NO") << '\n';
    }    

    return 0;
}