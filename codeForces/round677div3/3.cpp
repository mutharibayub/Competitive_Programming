#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

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
        bool ok = false;
        for(int i=1;i<n&&!ok;i++)
        {
            if(arr[i]!=arr.front())ok=true;
        }
        if(!ok)
        {
            cout << -1 << endl;
        }
        else
        {
            int mx = -1;
            for(int i=0;i<n;i++)mx=max(arr[i], mx);
            for(int i=0;i<n;i++)
            {
                if(arr[i]==mx)
                {
                    int prev = i?arr[i-1]:mx;
                    int next = i+1<n?arr[i+1]:mx;
                    if(next!=mx||prev!=mx)
                    {
                        cout << i+1 << endl;
                        break;
                    }
                }
            }
        }
    }


    return 0;
}