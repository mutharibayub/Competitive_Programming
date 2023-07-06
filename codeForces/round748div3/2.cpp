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

int cnt(const string &num, const string &digits)
{
    int loc = -1;
    for(int i=num.size()-1;i>=0;i--)
    {
        if(num[i]==digits[1])
        {
            loc=i;
            break;
        }
    }
    if(loc==-1)return 1e9+7;
    int tmp = loc-1;
    loc=-1;
    for(int i=tmp;i>=0;i--)
    {
        if(num[i]==digits[0])
        {
            loc=i;
            break;
        }
    }
    if(loc==-1)return 1e9+7;
    return num.size()-loc-2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        string num;
        cin>>num;
        string check[4] = {"00","25","50","75"};
        int ans = 1e9+7;
        for(int i=0;i<4;i++)
        {
            ans = min(ans, cnt(num, check[i]));
        }
        cout << ans << '\n';
    }    

    return 0;
}