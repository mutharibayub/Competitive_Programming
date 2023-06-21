#include <iostream>
#include <vector>

using namespace std;

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
        int mnOdd = 1e9+7;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2)mnOdd=min(mnOdd, arr[i]);
        }
        if(mnOdd == 1e9+7)mnOdd = 0;
        bool allEven = true;
        bool allOdd = true;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2&&arr[i]<=mnOdd)
            {
                allEven&=false;
            }
            if(arr[i]%2==0&&arr[i]<=mnOdd)
            {
                allOdd&=false;
            }
        }
        cout << ((allOdd||allEven)?"YES":"NO") << '\n';
    }
    return 0;
}