#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

typedef long long ll;

const ll inf = 2e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        priority_queue<int, vector<int>, greater<int>> pqA, pqB, pq2;
        int n, k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int t, a, b;
            cin>>t>>a>>b;
            if(a&&b)
            {
                pq2.push(t);
            }
            else if(a)
            {
                pqA.push(t);
            }
            else if(b)
            {
                pqB.push(t);
            }
        }
        bool ok = true;
        int ans = 0;
        for(int i=0;i<k&&ok;i++)
        {
            int first = pq2.size()?pq2.top():inf;
            int second = pqA.size()&&pqB.size()?pqA.top()+pqB.top():inf;
            if(first == inf && second == inf)
            {
                ok = false;
            }
            else if(first < second)
            {
                ans += first;
                pq2.pop();
            }
            else
            {
                ans += second;
                pqA.pop();pqB.pop();
            }
        }
        cout << (ok?ans:-1) << '\n';
    }
    return 0;
}