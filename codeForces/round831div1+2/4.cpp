#include <iostream>
#include <vector>
#include <queue>

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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> arr(k);
        for(int i=0;i<k;i++)cin>>arr[i];
        priority_queue<int> q;
        int nextReq = k;
        bool possible = true;
        for(int i=0;i<k;i++)
        {
            while(!q.empty() && q.top()==nextReq)
            {
                q.pop();
                nextReq--;
            }
            if(arr[i]==nextReq)
            {
                nextReq--;
            }
            else
            {
                q.push(arr[i]);
                if(q.size() > n*m-4)
                {
                    possible=false;
                    break;
                }
            }
        }
        if(possible)
        {
            cout << "YA\n";
        }
        else
        {
            cout << "TIDAK\n";
        }
    }

    return 0;
}