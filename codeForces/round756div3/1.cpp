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
        string s;
        cin>>s;
        if((s.back()-'0')%2==0)cout << 0 << '\n';
        else if((s.front()-'0')%2==0)cout << 1 << '\n';
        else 
        {
            bool ok=false;
            for(int i=0;i<s.size()&&!ok;i++)
            {
                if((s[i]-'0')%2==0)
                {
                    ok=true;
                }
            }
            cout << (ok?2:-1) << '\n';
        }
    }    

    return 0;
}