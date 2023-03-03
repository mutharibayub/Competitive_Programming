#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

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
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        ll pw = 0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0&&pq.size())
            {
                pw+=pq.top();
                pq.pop();
            }
            else if(arr[i])
            {
                pq.push(arr[i]);
            }
        }
        cout << pw << '\n';
    }

    return 0;
}