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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n); 
        for(int i=0;i<n;i++)cin>>arr[i];
        int64_t sum=0;
        for(int i=0;i<k;i++)
        {
            int maxVal = INT_MIN;
            for(int j=i;j<n;j+=k)
            {
                maxVal = max(maxVal, arr[j]);
            }
            sum+=maxVal;
        } 
        cout << sum << '\n';
    }


    return 0;
}