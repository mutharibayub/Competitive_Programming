#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int cnts[1<<26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int wc;
    cin>>wc;
    vector<string> wds(wc);
    for(int i=0;i<wc;i++)cin>>wds[i];
    vector<int> a(wc,0), b(wc,0);
    for(int i=0;i<wc;i++)
        for(int j=0;j<wds[i].size();j++)
        {
            a[i]|=(1<<(wds[i][j]-'a'));
            b[i]^=(1<<(wds[i][j]-'a'));
        }

    ll ans = 0;

    for(int i=0;i<26;i++)
    {
        for(int j=0;j<wc;j++)
        {
            if(!(a[j]&(1<<i)))
            {
                cnts[b[j]]++;
                ans += cnts[((1<<26)-1)^b[j]^(1<<i)];
            }
        }

        for(int j=0;j<wc;j++)
        {
            if(!(a[j]&(1<<i)))cnts[b[j]]--;
        }
    }

    cout << ans << '\n';



    return 0;
}