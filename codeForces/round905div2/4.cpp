#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> a(n), b(n);
        a[0] = 0;
        for(int i = 1; i < n; i++)
            cin>>a[i];
        for(int i = 0; i < n; i++)
            cin>>b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> leftMx(n, 0), rightMx(n, 0);
        for(int i = 1; i < n; i++)
        {
            leftMx[i] = lower_bound(b.begin() + i - 1, b.end(), a[i] + 1) - (b.begin() + i - 1);
            rightMx[i] = lower_bound(b.begin() + i, b.end(), a[i] + 1) - (b.begin() + i);
        
            leftMx[i] = max(leftMx[i], leftMx[i-1]);
        }
        long long ans = 0;
        for(int i = n-2; i >= 0; i--)
            rightMx[i] = max(rightMx[i], rightMx[i+1]);
        vector<int> vals = a;
        vals.insert(vals.end(), b.begin(), b.end());
        vals.push_back(m+1);
        sort(vals.begin(), vals.end());
        int lwr = 1;
        for(int j = 0; j < vals.size(); j++)
        {
            int upr = vals[j];
            if(upr > m+1)
                break;
            if(upr - lwr < 1)
                continue;
            int i = lwr;
            int loc = lower_bound(a.begin(), a.end(), i + 1) - a.begin();
            int mx = lower_bound(b.begin() + loc - 1, b.end(), i + 1) - (b.begin() + loc - 1);
            if (loc < n)
                mx = max(mx, rightMx[loc]);
            if (loc > 0)
                mx = max(mx, leftMx[loc - 1]);
            ans += mx * 1ll * (upr - lwr);
            lwr = upr;
        }
        cout << ans << '\n';
    }
    return 0;
}