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
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> cnt(26, 0);
        for(int i=0;i<n;i++)
        {
            cnt[s[i]-'a']++;
        }
        int pairs=0;
        for(int i=0;i<26;i++)
        {
            pairs+=cnt[i]/2;
        }
        pairs = pairs/k*k;
        int lessCount = k;
        int remaining = n-pairs*2;
        
        cout << 2*(pairs/k) + (remaining>=lessCount) << '\n';

    }    

    return 0;
}