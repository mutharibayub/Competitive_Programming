#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=n-1;i>0;i--)
        {
            while(arr[i]<=arr[i-1])
            {
                if(arr[i-1]==0)
                {
                    cnt=-1;
                    break;
                }
                arr[i-1]/=2;
                cnt++;
            }
            if(cnt==-1)break;
        }
        cout << cnt << '\n';
    }

    return 0;
}