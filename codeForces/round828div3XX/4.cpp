#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> twos;
        int curTwos = n;
        twos.reserve(n);
        for(int i=0;i<n;i++)
        {
            int tmp = i+1, count = 0;
            while(tmp && !(tmp&1))
            {
                tmp = tmp >> 1;
                count++;
            }
            twos.push_back(count);
            int v;
            cin>>v;
            while(v && !(v&1))
            {
                v = v >> 1;
                curTwos--;
            }
        }
        // cout << "curTwos: " << curTwos << '\n';
        int ans = 0;
        sort(twos.rbegin(), twos.rend());
        for(int i=0;i<twos.size()&&curTwos>0;i++)
        {
            if(twos[i] <= curTwos)
            {
                curTwos -= twos[i];
                ans ++;
            }
        }
        if(curTwos<=0)
        {
            cout << ans << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }

    return 0;
}