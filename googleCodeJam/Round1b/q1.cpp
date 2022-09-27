#include <iostream>
#include <vector>

using namespace std;

void testCase()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ptr1=0,ptr2=n-1;
    int max=-1;
    int count=0;
    while(ptr1<=ptr2)
    {
        if(arr[ptr1]<arr[ptr2])
        {
            if(arr[ptr1]>=max)
            {
                max=arr[ptr1];
                count++;
            }
            ptr1++;
        }
        else
        {
            if(arr[ptr2]>=max)
            {
                max=arr[ptr2];
                count++;
            }
            ptr2--;            
        }
    }
    cout<<count<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        testCase();
    }

    return 0;
}