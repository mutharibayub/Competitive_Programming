#include <iostream>
#include <vector>
#include <string>

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
        for(int i=0;i<n;i++) cin>>arr[i];
        ll sum = 0;
        int count = 0;
        bool off = true;
        for(int i=0;i<n;i++)
        {
            sum += abs(arr[i]);
            if(!count && arr[i]<0)count++, off=false;
            else if(off&arr[i]<0)count++, off=false;
            if(arr[i]>0)off=true;
        }
        cout << sum << ' ' << count << '\n';
    }   
    return 0;
}