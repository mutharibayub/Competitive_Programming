#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tttt;
    cin>>tttt;
    for(int ttt=1;ttt<=tttt;ttt++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> state(n+1, 0), cnt(n+1, 0);
        for(int i=0;i<n;i++)
            state[i+1]=s[i]-'0';
        int sm=0;
        for(int i=1;i<=n;i++)
        {
            if(state[i])
            {
                state[i]=0;
                cnt[i]=1;
                sm++;
                for(int j=i;j<=n;j+=i)
                {
                    state[j]^=1;
                }
            }
        }
        long long ans = 0;
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int tmp;
            cin>>tmp;
            sm -= cnt[tmp];
            cnt[tmp] ^= 1;
            sm += cnt[tmp];
            ans += sm;
        }
        cout << "Case #" << ttt << ": " << ans << '\n';
    }

    return 0;
}
