#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
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
        ll sum=0;
        int negCount=0;
        int minNum=1e9+7;
        for(int i=0;i<n;i++)
        {
            minNum=min(minNum, abs(arr[i]));
            negCount+=arr[i]<0;
            sum+=abs(arr[i]);
        }
        if(negCount%2)
        {
            cout << sum-2*minNum << '\n';
        }
        else
        {
            cout << sum << '\n';
        }
    }

    return 0;

}