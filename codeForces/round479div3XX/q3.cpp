#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,k;
    vector<int> arr;
    
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    if(k==n)
    {
        cout<<arr.back()<<'\n';
    }
    else if(arr[k]>arr[k-1])
    {
        cout<<arr[k-1]<<'\n';
    }
    else
    {
        cout<<"-1\n";
    }

    return 0;
}