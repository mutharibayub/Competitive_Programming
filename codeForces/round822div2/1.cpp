#include <iostream>
#include <vector>
#include <algorithm>

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
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int minSteps = 1e9+7;
        for(int i=0;i<arr.size()-2;i++)
        {
            if(arr[i]==arr[i+1] && arr[i+1]==arr[i+2])
            {
                minSteps = min(minSteps,0);
            }
            else if(arr[i]==arr[i+1])
            {
                minSteps = min(minSteps, arr[i+2]-arr[i+1]);
            }
            else if(arr[i+1]==arr[i+2])
            {
                minSteps = min(minSteps, arr[i+1]-arr[i]);
            }
            else
            {
                minSteps = min(minSteps, arr[i+2]-arr[i]);
            }
        }
        cout << minSteps << '\n';
    }


    return 0;
}