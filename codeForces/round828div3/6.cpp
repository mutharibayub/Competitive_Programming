#include <iostream>
#include <vector>
#include <queue>
#include <string>

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
        vector<int> arr(n), loc(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            loc[arr[i]]=i;
        }
        int l,r,next=1;
        priority_queue<int, vector<int>, greater<int>> q;
        ll ans = 0;
        l=r=loc[0];
        while(l>=0 && r<=n-1)
        {
            int size = r-l+1;
            int maxSizeAllowed = next*2;
            if(next<=n-1 && loc[next]<l)
            {
                if(size<=maxSizeAllowed)
                {
                    int R = min(l+maxSizeAllowed-1, n-1);
                    ans += R-r+1;
                }
                l--;
                q.push(arr[l]);
            }
            else
            {
                if(size<=maxSizeAllowed)
                {
                    int L = max(r-maxSizeAllowed+1, 0);
                    ans += l-L+1;
                }
                r++;
                if(r<=n-1)q.push(arr[r]);
            }
            while(q.size() && q.top()==next)
            {
                q.pop();
                next++;
            }
        }
        cout << (ans?ans:1) << '\n';
    }

    return 0;
}