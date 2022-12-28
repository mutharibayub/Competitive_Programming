#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int64_t fact(int64_t n)
{
    if(n==0 || n==1)return 1;
    int64_t a=n;
    for(int64_t i=2;i<n;i++)
    {
        a*=i;
    }
    return a;
}

void testCase()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> sorted(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sorted[i]=arr[i];
    }
    sort(sorted.begin(),sorted.end());
    int left=n;
    for(int i=0;i<n;i++,left--)
    {
        if(left%2 && arr[i]!=sorted[i])
        {
            cout<<"NO\n";
            return;
        }
        else if(left%2==0)
        {
            if(arr[i]==sorted[i])
            {}
            else if(arr[i+1]==sorted[i])
            {
                arr[i+1]=arr[i];
            }
            else
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--)
    {
        testCase();
    }

    return 0;
}