#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int minHits = 1e9+7;
    int min1=1e9+7,min2=1e9+7;
    for(int i=0;i<n;i++)
    {
        if(i&&i<n-1)
        {
            int a=arr[i-1], b=arr[i+1];
            if(b>a)swap(a,b);
            minHits = min(minHits, b+(a-b+1)/2);
        }
        if(i<n-1)
        {
            int a=arr[i], b=arr[i+1];
            if(b>a)swap(a,b);
            if((a+1)/2>b)
            {
                minHits=min(minHits, (a+1)/2);
            }
            else
            {
                int c = (a-b);
                a-=c*2;
                b-=c;
                c+=(a+b+2)/3;
                minHits=min(minHits, c);
            }
        }
        min2=min(min2, (arr[i]+1)/2);
        if(min2<min1)swap(min1,min2);
        minHits=min(minHits, min1+min2);
    }
    cout << minHits << '\n';

    return 0;
}