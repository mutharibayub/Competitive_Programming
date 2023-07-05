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
        string s;
        cin>>s;
        int cnt=0;
        while(cnt<s.size()&&s[cnt]==PI[cnt])cnt++;
        cout << cnt << '\n';
    }    

    return 0;
}